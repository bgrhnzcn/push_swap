ARGS=$(python3 Tester.py $1)
RES=$(./push_swap $ARGS | ./checker_linux $ARGS)
if [ "$RES" = "KO" ]; then
	echo "$RES"
	echo "----"
	./push_swap $ARGS
else
	./push_swap $ARGS | wc -l
fi
