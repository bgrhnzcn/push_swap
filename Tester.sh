if ! test -f ./push_swap; then
	make re
	make clean
fi
i=0
total=0
while [ $i -lt $2 ]
do
	((i++))
	ARGS=$(python3 rnd_list_gen.py $1)
	if [ "Linux" = "$(uname)" ]; then
		res=$(./push_swap $ARGS | ./checker_linux $ARGS)
	else
		res=$(./push_swap $ARGS | ./checker_Mac $ARGS)
	fi
	if [ "$res" = "KO" ]; then
		echo "$res"
		echo "----"
		./push_swap $ARGS
		break
	else
		echo "$res"
		move=$(./push_swap $ARGS | wc -l)
		if [ $1 -eq 5 ] && [ $move -gt 12 ]; then
			echo "Test Failed."
			break
		fi
		((total += move))
		python3 -c "print('Test$i Result: $move')"
	fi
done
python3 -c "print('Average: ' + str($total/$i))"
