# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    rangen.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaltayeh <yaltayeh@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 21:16:33 by yaltayeh          #+#    #+#              #
#    Updated: 2024/11/02 21:16:48 by yaltayeh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import os
import random

argc = len(sys.argv)

if argc != 2:
	os.write(2, b"Enter random array len")
	exit(1)

array = random.sample(range(-2147483648, 2147483647), int(sys.argv[1]))

print(*array, sep=" ")