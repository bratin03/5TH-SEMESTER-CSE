import sys
import re
import json

REGDICT = {}
INSTRUCTION_DICT = {}
OUTPUT_FILE = open("output.txt", "w")


def two_comp(num, nbits):
  '''
    gives nbit long two complement representation of number
    '''
  if num >= 0:
    return f"{num:0{nbits}b}"
  else:
    return f"{((1<<nbits)+num):0{nbits}b}"


def spit_line(line):
  try:
    opcode = INSTRUCTION_DICT[line[0]][0]
    opc = int(opcode, 2)
    if opc == 1 or opc == 2:
      if len(line) != 4 and (len(line) == 3
                             and INSTRUCTION_DICT[line[0]][-1] != "000011"):
        print(f"error in line {line}")
        return
      else:
        funct = f"{INSTRUCTION_DICT[line[0]][-1]}"
        rd = f"{REGDICT[line[1]]:05b}"
        rs = f"{REGDICT[line[2]]:05b}"
        if (funct != "000011"):
          rt = f"{REGDICT[line[3]]:05b}"
        else:
          rt = f"{0:05b}"
        shamt = f"{0:05b}"
        print(f"{opcode}{rd}{rs}{rt}{shamt}{funct},", file=OUTPUT_FILE)
    elif opc == 3:
      if len(line) != 3:
        print(f"error in line {line}")
        return
      else:
        rd = f"{REGDICT[line[1]]:05b}"
        rs = f"{REGDICT[line[2]]:05b}"
        funct = f"{INSTRUCTION_DICT[line[0]][-1]}"
        shamt = f"{0:05b}"
        print(f"{opcode}{shamt}{rd}{rs}{shamt}{funct},", file=OUTPUT_FILE)
    elif opc == 48 or opc == 49 or opc == 50 or opc == 51 or opc == 52:
      if len(line) != 3:
        print(f"error in line {line}")
        return
      else:
        rs = f"{REGDICT[line[1]]:05b}"
        rt = f"{0:05b}"
        imm_dec = int(line[2])
        imm = two_comp(imm_dec, 11)
        print(f"{opcode}{rs}{rs}{rt}{imm},", file=OUTPUT_FILE)
    elif opc == 53 or opc == 54 or opc == 55:
      if len(line) != 3:
        print(f"error in line {line}")
      else:
        rs = f"{REGDICT[line[1]]:05b}"
        imm_dec = int(line[2])
        print(imm_dec)
        waste = f"{0:015b}"
        print(f"{opcode}{rs}{rs}{waste}{imm_dec},", file=OUTPUT_FILE)

    elif opc == 62 or opc == 63:
      if len(line) != 4:
        print(f"error in line {line}")
        return
      else:
        rt = f"{REGDICT[line[1]]:05b}"
        rs = f"{REGDICT[line[-1]]:05b}"
        bin = f"{0:05b}"
        imm_dec = int(line[2])
        imm = two_comp(imm_dec, 11)
        print(f"{opcode}{bin}{rs}{rt}{imm},", file=OUTPUT_FILE)
    elif opc == 4 or opc == 5 or opc == 6 or opc == 7:
      if (opc == 4):
        imm_dec = int(line[1])
        imm = two_comp(imm_dec, 16)
        bin = f"{0:010b}"
        print(f"{opcode}{bin}{imm},", file=OUTPUT_FILE)
      else:
        imm_dec = int(line[2])
        imm = two_comp(imm_dec, 16)
        rs = f"{REGDICT[line[1]]:05b}"
        bin = f"{0:05b}"
        print(f"{opcode}{bin}{rs}{imm},", file=OUTPUT_FILE)

  except:
    print(f"error in line {line}")


def bin_comm(string):
  string = re.sub(re.compile("/'''.*?\'''", re.DOTALL), "", string)
  string = re.sub(re.compile("#.*?\n"), "", string)
  return string


def process(filename):
  print("memory_initialization_radix=2;", file=OUTPUT_FILE)
  print("memory_initialization_vector=", file=OUTPUT_FILE)
  print(f"{0:032b}", file=OUTPUT_FILE)
  with open(filename, 'r') as f:
    lines = f.readlines()
    for line in lines:
      line.strip()
      line = bin_comm(line)

      line = line.replace(',', ' ').replace(')', ' ').replace('(', ' ').split()
      if len(line):
        if (line[0] == "stsp"):
          line[0] = "st"
        elif (line[0] == "ldsp"):
          line[0] = "ld"
        elif (line[0] == "move"):
          rs = line[2]
          rd = line[1]
          line1 = ["xor", rd, rd, rd]
          line2 = ["add", rd, rd, rs]
          spit_line(line1)
          line = line2
        if(line[0]=="nop"):
          bin = f"{0:032b}"
          print(f"{bin},", file=OUTPUT_FILE)
        else:
          spit_line(line)
  print(f"{0:032b};", file=OUTPUT_FILE)


if __name__ == '__main__':
  with open('instruc.json', 'r') as f:
    INSTRUCTION_DICT = json.load(f)
  with open('registers.json', 'r') as f:
    REGDICT = json.load(f)
  process('test.s')
