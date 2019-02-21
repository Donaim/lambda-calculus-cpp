
if ./test.exe 2> errors.txt 1> output.txt
then
	if cat output.txt | grep '  = false' -q; then
		echo 'Wrong output'
		cat output.txt
		exit 1
	fi
else
	status=$?
	echo 'Error exit code: $status'
	exit $status
fi

rm test.exe test.c || exit 1

cat output.txt
echo OK
