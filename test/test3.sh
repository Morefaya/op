#!/bin/zsh

ok="\033[32mOK\033[0m"
ko="\033[31mK0\033[0m"

i=1

fct_test()
{
	echo -n "test $i: \t"
	local ret=$(../op $1)
	if [ "$ret" = "$2" ]
	then
		echo " " $ok
	else
		echo " " $ko "arg: $1 / ret: $ret / expected: $2"
	fi
	let i++
}


input=("(hello)"); ret='hello'
fct_test $input $ret

input=("(hello)     "); ret='hello'
fct_test $input $ret

input=("its me"); ret=""
fct_test $input $ret

input=("its me  my (baby)  (boo)"); ret="baby boo"
fct_test $input $ret

input=("its me (i was) (wond"); ret="i was"
fct_test $input $ret

input=("its me (i was) (wondering) if after"); ret="i was wondering"
fct_test $input $ret

input=("its me (i was) (wondering) if after(all"); ret="i was wondering"
fct_test $input $ret

input=("its me (i was) (wondering) if after(all)"); ret="i was wondering all"
fct_test $input $ret

input=("its me (i was) (wondering(me)) if after(all)"); ret="i was wondering(me) all"
fct_test $input $ret

input=("its me (i was(si  ())) (wondering) if after(all)"); ret="i was(si  ()) wondering all"
fct_test $input $ret
