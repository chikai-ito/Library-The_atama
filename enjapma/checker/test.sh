#!/bin/sh

g++ -O2 main.cpp -o main
g++ -O2 generator.cpp -o generator
g++ -O2 simple.cpp -o simple

random="test/random.txt"

for i in `seq -w 60`
do
	echo "testing case${i}"
	input="test/case${i}/testcase_${i}.txt"
	simple_output="test/case${i}/simple_output_${i}.txt"
	main_output="test/case${i}/main_output_${i}.txt"
	./generator > ${input}
	./simple < ${input} > ${simple_output}
	./main < ${input} > ${main_output}
	diff -q ${simple_output} ${main_output}
done

rm main
rm generator
rm simple
