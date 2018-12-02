#!/bin/zsh

ok="\033[32mOK\033[0m"
ko="\033[31mK0\033[0m"

fct_test()
{
	echo -n $1
	../op $1 >> /dev/null
	ret=$?
	if [ $ret -eq $2 ]
	then
		echo " " $ok "ret: $ret expected: $2"
	else
		echo " " $ko "ret: $ret expected: $2"
	fi
}

input=('1234567891'); ret=9
echo "==========test 1============"
fct_test $input $ret
echo "============================\n"

input=('1234567891234567891'); ret=18
echo "==========test 2============"
fct_test $input $ret
echo "============================"
