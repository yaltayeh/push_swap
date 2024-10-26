ARGS=$(python3 rangen.py 100)
echo $ARGS

./push_swap $ARGS | ./checker_linux $ARGS