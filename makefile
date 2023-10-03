all: hw1

run:main.c
	make hw1
	./hw1

hw1:main.c
	gcc main.c -o  hw1 -lm

doc: main.tex
	pdflatex -shell-escape main.tex -o main.pdf

hello:
	echo hello

clean:
	rm hw1