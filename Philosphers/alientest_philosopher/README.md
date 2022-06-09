# alientest_philosopher

Clone this repo at your philosopher's root (at the same level of your philo_one, philo_two and philo_three directories).

Basic usage : 'bash test.sh'

How to read the output : 
	green tick : test passed
	red cross : test failed

This tester is not enough to validate the project, remember to also test :
- norm
- each program without a 5th argument
- check the coherence of the output
- ask for explanations on the choices that were made and the issues encountered

To run only one test or valgrind with your own args, you can use :
- bash one.sh 
- bash valgrind.sh
with the same args as if you were executing one of your philosophers + the nb of the philo you want to test as the first arg
ex : "bash one.sh 1 2 10 5 5" (launches ./philo_one 2 10 5 5)

To run only test.sh on only one philosopher, add the philosopher's nb in args.
ex : 'bash test.sh 2' -> runs the script only for philo_two

To run only valgrind tests : 'bash leak_test.sh'
To run only leak_test.sh on only one philosopher, add the philosopher's nb in args.
ex : 'bash leak_test.sh 2' -> runs the script only for philo_two
