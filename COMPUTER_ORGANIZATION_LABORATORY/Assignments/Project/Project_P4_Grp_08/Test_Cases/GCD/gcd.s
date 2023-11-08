xor $2,$2,$2
xor $3,$3,$3
addi $2, 63
addi $3, 8
xor $4,$4,$4
add $4,$4,$2
xor $5,$5,$5
add $5,$5,$3
bz $4,15
nop
bz $5,17
nop
sub $6,$4,$5
bmi $6,5
nop
xor $4,$4,$4
add $4,$4,$6
br -10
nop
sub $6,$5,$4
xor $5,$5,$5
add $5,$5,$6
br -13
nop
xor $1,$1,$1
add $1,$1,$5
br 3
nop
xor $1,$1,$1
add $1,$1,$4
