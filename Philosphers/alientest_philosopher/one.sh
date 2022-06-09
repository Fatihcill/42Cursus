
read  -n 1 -p "
Usage : bash one.sh philo_one_or_two_or_three (1 for philo_one, 2 for philo_two, 3 for philo_three) Nb_philo T_to_die T_to_eat T_to_sleep 

ex : bash one.sh 1 2 10 5 5 -> (launches ./philo_one 2 10 5 5)

if you dit it right, press enter, if not, ctrl+C
" input

if [ "$1" == "1" ];
then
	philo="philo_one"
elif [ $1 == 2 ];
then
	philo="philo_two"
elif [ $1 == 3 ];
then
	philo="philo_three"
fi

make -C ../$philo

if [ "$6" != "" ];
then
	./../$philo/$philo $2 $3 $4 $5 $6
else
	./../$philo/$philo $2 $3 $4 $5
fi
