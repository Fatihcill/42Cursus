#!/bin/bash

PHILOSOPHES=$(ls ../ | grep -v "README" | grep -v alientest_philosopher)
for compil in ${PHILOSOPHES[*]}
do
	make -C ../$compil fclean
done
