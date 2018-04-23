#!bin/bash
# **************************************************************************** #
PROGRAMDIR=.
MAPDIR=./map/
MAP_ERROR="empty_square full_square less_hash_00 less_hash more_hash corner_hash"
MAP_VALID="4,7s 7,4s 9s 10s 11,4s 13,1s 16,2s 26,4s"
MAP_CORR="test1 test7"
# **************************************************************************** #
if [ $# -eq 0 ]
then
	#norminette -R CheckForbiddenSourceHeader $PROGRAMDIR
	echo "\nRunning error maps :"
	for MAP in $MAP_ERROR
	do
		echo "\n"$MAP".fillit"
		$PROGRAMDIR/fillit $MAPDIR$MAP.fillit
	done
	echo "\nRunning correction maps :"
	for MAP in $MAP_CORR
	do
		echo "\n"$MAP".fillit"
		time $PROGRAMDIR/fillit $MAPDIR$MAP.fillit
	done
	echo "\nRunning valid maps :"
	for MAP in $MAP_VALID
	do

		echo "\n"$MAP".fillit"
		time $PROGRAMDIR/fillit $MAPDIR$MAP.fillit
	done	
else
	echo "Usage: sh map_runner.sh [void] cimer"
fi
