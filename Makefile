# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmartin <bmartin@student.42quebec.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 11:31:23 by bmartin           #+#    #+#              #
#    Updated: 2023/03/03 14:00:10 by bmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#                 \ \ / /_\ | _ |_ _| /_\ | _ | |  | __/ __|                   
#                  \ V / _ \|   /| | / _ \| _ | |__| _|\__ \                    
#                   \_/_/ \_|_|_|___/_/ \_|___|____|___|___/                   


######################_____________VARIABLES______________######################


# add colors
G = \033[0;32m
RT = \033[0m

# NAME_OF_THE_PROGRAM (exemple:   a.out    )
NAME	= push_swap

# COMPILER
CC		= gcc

# COMPILER FLAGS
CFLAGS	= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast

# LIBRARY
LIBFT	= libft
LIBS	=  libft/libft.a

# DIRECTORY FOR HEADER FILE
HEADERS	= -I ./include -I $(LIBMLX)/include

# SOURCE FILE FOR THE PROGRAM (   int main   )
SRCS	=	src/main.c \
			src/error.c \
			src/sort.c  \
			src/sort_utils.c  \
			src/check_arg.c \
			src/create_list.c \
			src/create_list_utils.c \
			src/push.c \
			src/swap.c \
			src/rotate.c\
			src/big_sort.c 

# THE DIRECTORY FOR OBJECT FILES 
OBJDIR	=	bin/

SRCDIR	=	src/

#THE OBJECT FILES WICH ARE GENERATED FROM THE SOURCE FILES
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))


#                        _____ _   ___  ___ ___ _____                         
#                       |_   _/_\ | _ \/ __| __|_   _|                         
#                         | |/ _ \|   | (_ | _|  | |                          
#                         |_/_/ \_|_|_\\___|___| |_|                           

######################______________TARGET______________######################



###  @echo :  prints the specified text to the console

#The target "all" compiles the program, and prints a message to remind the user
# of the "play" target. It depends on the "libs_make" target and the program itself.
all: mk_bin libs_make $(NAME)
	
	
# The target "mk_bin" creates the "bin" directory if it doesn't exist already
mk_bin:
	@mkdir -p $(OBJDIR)
	
#The target "libs_make" makes the libraries required for the program.	
libs_make:
	@$(MAKE) -C $(LIBFT)

#The target "$(OBJS)" generates object files from the source files.
# It uses the CC compiler, the CFLAGS flags, and the HEADERS directories.
# REMOVE LFLAGS to not use fsanitizer
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	@$(CC)  $(CFLAGS) -c $< -o $@ $(HEADERS)

# The target "$(NAME)" links the object files to create the final program.
#  It links the LIBS libraries, the HEADERS directories, and adds additional framework dependencies.
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) 

	@echo "$(G)\n ║ MAKE COMPLETE 🥳 ║$(RT)"
	@echo "\n make sort  \ RUN$(RT)"
	@echo " make leaks   \\ RUN + LEAKS CHECK $(RT)"
	@echo " make valgrind   \\ RUN + VALGRIND CHECK $(RT)"
	@echo " make check   \\ RUN + visualizer CHECK $(RT)"


#The target "clean" removes the object files and cleans the libraries.
clean:
	@echo "\n$(R)clean target called$(RT)"
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@echo "$(G)Libft Cleaned$(RT)\n"

#The target "fclean" removes the final program and cleans the libraries.
fclean: clean rm_bin
	@echo "\n$(R)fclean target called$(RT)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@echo "$(G)Libft Cleaned$(RT)"

#The new target "rm_bin" removes the "bin" directory.
rm_bin:
	@rm -rf $(OBJDIR)

#The target "re" is a shortcut for "fclean" followed by "all".
re: fclean all

#The target "leaks" runs the program with the "leaks" tool to check for memory leaks.
leaks: all
	leaks -atExit -- ./push_swap 5 3 2 4 1

#give the details about the leaks of your program (valgrind needed)
valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./push_swap "123 1 2" "654 456 123"

#The target "play" builds the program and runs it with a specific map file.
sort: all
	./push_swap 1 4 3 2 5 6 7 8 9 31 42 64 74 86
	
check: all
	cd visualizer/build && ./bin/visualizer

###   CODE BANNER STYLE   ###
###   https://manytools.org/hacker-tools/ascii-banner/   ##
## font : small  / squeezed / squeezed


