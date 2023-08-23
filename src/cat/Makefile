ASAN=#-fsanitize=address -fanalyzer

s21_cat: 
	gcc -Wall -Werror -Wextra -std=c11 -pedantic $(ASAN) s21_cat.c s21_cat_support.c -o s21_cat

.PHONY: s21_cat

test: s21_cat
	./s21_cat -b test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test1.txt
	cat -b test1.txt test2.txt test3.txt test4.txt test5.txt > cat_test1.txt
	diff -s s21_test1.txt cat_test1.txt
	./s21_cat -e test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test2.txt
	cat -e test1.txt test2.txt test3.txt test4.txt test5.txt > cat_test2.txt
	diff -s s21_test2.txt cat_test2.txt
	./s21_cat -n test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test3.txt
	cat -n test1.txt test2.txt test3.txt test4.txt test5.txt > cat_test3.txt
	diff -s s21_test3.txt cat_test3.txt
	./s21_cat -s test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test4.txt
	cat -s test1.txt test2.txt test3.txt test4.txt test5.txt > cat_test4.txt
	diff -s s21_test4.txt cat_test4.txt
	./s21_cat -t test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test5.txt
	cat -t test1.txt test2.txt test3.txt test4.txt test5.txt > cat_test5.txt
	diff -s s21_test5.txt cat_test5.txt
	
clean: 
	rm -f cat*.txt
	rm -f s21*.txt
	rm -f s21_cat