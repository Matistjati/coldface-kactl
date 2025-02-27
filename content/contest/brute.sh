g++ -fsanitize=undefined,address -Wall -g -O2 ac.cpp -o ac
g++ -fsanitize=undefined,address -Wall -g -O2 wa.cpp -o wa
while true; do
    python3 gen.py > in.txt
    ./ac < in.txt > ansac.txt
    ./wa < in.txt > answa.txt
    diff ansac.txt answa.txt || exit
done
