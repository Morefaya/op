#!/bin/zsh

ok="\033[32mOK\033[0m"
ko="\033[31mK0\033[0m"


fct_test()
{
	i=1
	echo -n $1 $2
	../ft_regex $1 $2 >> /dev/null
	if [ $? -ne $3 ]
	then
		echo " " $ok
	else
		echo " " $ko
	fi
}


tab=('oui' 'oui'); ret=1
echo "==========test dot=========="
fct_test $tab $ret
echo "============================\n"

tab=('oui' 'ou*'); ret=1
echo "==========test dot=========="
fct_test $tab $ret
echo "============================\n"

tab=('oui' 'o.i'); ret=1
echo "==========test dot=========="
fct_test $tab $ret
echo "============================\n"

tab=('azerty' 'cajnl'); ret=0
echo "==========test dot=========="
fct_test $tab $ret
echo "============================\n"
