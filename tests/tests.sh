1_BEGIN__LIST ALL FILES___

mkdir tests && cd tests && touch 1 2 3 4 a b c d e .hide_me && cd ..
./ft_ls tests | cat > mine
ls -1 tests | cat > real
diff mine real

1_END_____________________
mkdir tests tests/1 tests/2 tests/3 tests/1/11 tests/2/22 tests/3/33 \
&& touch tests/1/empty tests/2/empty tests/3/empty tests/empty \

1_END_____________________
