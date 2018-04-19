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

if [ $# -eq 1 ]
then
	make && cat $1 && ./fillit $1
else
	echo "Usage: sh map_runner.sh [map.fillit] cimer"
fi