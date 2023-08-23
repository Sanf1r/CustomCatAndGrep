ASAN=#-fsanitize=address -fanalyzer

s21_grep:
	gcc -Wall -Werror -Wextra -std=c11 -pedantic s21_grep.c s21_grep_support.c -o s21_grep

.PHONY: s21_grep

test: s21_grep
	./s21_grep You test1.txt > s21_test1.txt
	grep You test1.txt > grep_test1.txt
	diff -s s21_test1.txt grep_test1.txt
	./s21_grep this test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test2.txt
	grep this test1.txt test2.txt test3.txt test4.txt test5.txt > grep_test2.txt
	diff -s s21_test2.txt grep_test2.txt
	./s21_grep -e You -e This -e me test1.txt > s21_test3.txt
	grep -e You -e This -e me test1.txt > grep_test3.txt
	diff -s s21_test3.txt grep_test3.txt
	./s21_grep -e Far -e Forrest -e me test5.txt > s21_test4.txt
	grep -e Far -e Forrest -e me test5.txt > grep_test4.txt
	diff -s s21_test4.txt grep_test4.txt
	./s21_grep -e You -e This -e me test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test5.txt
	grep -e You -e This -e me test1.txt test2.txt test3.txt test4.txt test5.txt > grep_test5.txt
	diff -s s21_test5.txt grep_test5.txt
	./s21_grep -i the test5.txt > s21_test6.txt
	grep -i the test5.txt > grep_test6.txt
	diff -s s21_test6.txt grep_test6.txt
	./s21_grep -i the test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test7.txt
	grep -i the test1.txt test2.txt test3.txt test4.txt test5.txt > grep_test7.txt
	diff -s s21_test7.txt grep_test7.txt
	./s21_grep -v the test5.txt > s21_test8.txt
	grep -v the test5.txt > grep_test8.txt
	diff -s s21_test8.txt grep_test8.txt
	./s21_grep -v the test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test9.txt
	grep -v the test1.txt test2.txt test3.txt test4.txt test5.txt > grep_test9.txt
	diff -s s21_test9.txt grep_test9.txt
	./s21_grep -c the test5.txt > s21_test10.txt
	grep -c the test5.txt > grep_test10.txt
	diff -s s21_test10.txt grep_test10.txt
	./s21_grep -c the test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test11.txt
	grep -c the test1.txt test2.txt test3.txt test4.txt test5.txt > grep_test11.txt
	diff -s s21_test11.txt grep_test11.txt
	./s21_grep -l the test5.txt > s21_test12.txt
	grep -l the test5.txt > grep_test12.txt
	diff -s s21_test12.txt grep_test12.txt
	./s21_grep -l the test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test13.txt
	grep -l the test1.txt test2.txt test3.txt test4.txt test5.txt > grep_test13.txt
	diff -s s21_test13.txt grep_test13.txt
	./s21_grep -n the test5.txt > s21_test14.txt
	grep -n the test5.txt > grep_test14.txt
	diff -s s21_test14.txt grep_test14.txt
	./s21_grep -n the test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test15.txt
	grep -n the test1.txt test2.txt test3.txt test4.txt test5.txt > grep_test15.txt
	diff -s s21_test15.txt grep_test15.txt
	./s21_grep -h the test5.txt > s21_test16.txt
	grep -h the test5.txt > grep_test16.txt
	diff -s s21_test16.txt grep_test16.txt
	./s21_grep -h the test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test17.txt
	grep -h the test1.txt test2.txt test3.txt test4.txt test5.txt > grep_test17.txt
	diff -s s21_test17.txt grep_test17.txt
	./s21_grep -f f_file.txt testGREP.txt > s21_test18.txt
	grep -f f_file.txt testGREP.txt > grep_test18.txt
	diff -s s21_test18.txt grep_test18.txt
	./s21_grep -o the test5.txt > s21_test19.txt
	grep -o the test5.txt > grep_test19.txt
	diff -s s21_test19.txt grep_test19.txt
	./s21_grep -o the test1.txt test2.txt test3.txt test4.txt test5.txt > s21_test20.txt
	grep -o the test1.txt test2.txt test3.txt test4.txt test5.txt > grep_test20.txt
	diff -s s21_test20.txt grep_test20.txt

clean: 
	rm -f grep*.txt
	rm -f s21*.txt
	rm -f s21_grep