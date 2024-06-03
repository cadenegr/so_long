# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cadenegr <cadenegr@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/14 14:55:14 by cadenegr          #+#    #+#              #
#    Updated: 2023/08/14 15:24:06 by cadenegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCDIR = src
OBJDIR = obj
LIBFTDIR = libft
MINILIBXDIR = minilibx-linux#added here

SRC_FILES = $(wildcard $(SRCDIR)/*.c)
#SRC = $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC_FILES))

LIBFT = $(LIBFTDIR)/libft_printf.a
MINILIBX = $(MINILIBXDIR)/libmlx.a#also added here
INCLUDES = -I./include -I$(LIBFTDIR)/include -I$(MINILIBXDIR)#added the last part -I$(MINILIBXDIR

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFTDIR) -lft_printf -L$(MINILIBXDIR) -lmlx -L/usr/X11/lib -lXext -lX11
RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME)
#$(MINILIBX)
$(NAME): $(LIBFT) $(MINILIBX) $(OBJDIR) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBFT):
	make -C $(LIBFTDIR)

#added here too	
$(MINILIBX):
	make -C $(MINILIBXDIR)

clean:
	$(RM) $(OBJDIR)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all


