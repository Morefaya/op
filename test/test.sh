#!/bin/zsh

ok="\033[32mOK\033[0m"
ko="\033[31mK0\033[0m"


fct_test()
{
	if [ $(($# % 2)) -ne 0 ]; then
		exit -1
	fi
	i=1
	len=$(($# / 2))
	while [ $i -le $len ]; do
		../ft_regex $@[1] $@[$i] >> /dev/null
		if [ $? -eq 0 ] && [ $@[$(($i+$len))] -eq 0 ]; then
			echo $ok
		elif [ $? -ne 0 ] && [ $@[$(($i+$len))] -ne 0 ]; then
			echo $ok
		else
			echo $ko
		fi	
		let i++;
	done
}

tab=("Im a boss" "Im a .boss" "Im a .oss")
ret=(1 0 1)
echo "==========test dot=========="
fct_test $tab $ret
echo "============================\n"


tab=("Hello its me" "Im a .boss" "hel.o its me" "Hello .ts me" "Hello its me dauyg Hello its me")
ret=(1 0 1 1 2)
echo "==========test dot=========="
fct_test $tab $ret
echo "============================\n"
