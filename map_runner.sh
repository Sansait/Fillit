# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    map_runner.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/19 03:02:49 by nihuynh           #+#    #+#              #
#    Updated: 2018/04/19 03:04:48 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/bash

if [ $# -eq 0 ]
then
	echo "Usage: sh map_runner.sh [void] cimer"
else
	for num
	do
   		time ./fillit $num
		echo "\t" $num
	done
fi