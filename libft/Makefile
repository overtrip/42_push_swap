# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jealonso <jealonso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/09 16:51:42 by jealonso          #+#    #+#              #
#    Updated: 2015/05/28 15:53:00 by jealonso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:

.PHONY: all re clean fclean casm ccf

NAME = libft.a

INCPATH = includes

OBJSPATH = objs

ASM = ~/.brew/Cellar/nasm/2.11.06/bin/nasm

AR = ar

RANLIB = ranlib

AFLAGS = -f macho64

SRCSPATH = srcs

SRCSASMPATH = asm

SRCS = \
	ft_atoi.c\
	ft_itoa.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memcmp.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcolor.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strisdigit.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_swap.c

SRCSASM = \
	ft_bzero.s \
	ft_isalnum.s \
	ft_isalpha.s \
	ft_isascii.s \
	ft_isdigit.s \
	ft_islower.s \
	ft_isprint.s \
	ft_isupper.s \
	ft_puts.s \
	ft_strcat.s \
	ft_strlen.s \
	ft_tolower.s \
	ft_toupper.s \
	ft_memset.s \
	ft_memcpy.s \
	ft_strdup.s \
	ft_cat.s \
	ft_strequ.s \
	ft_strcmp.s \
	ft_memchr.s \
	ft_memalloc.s \

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INCPATH)

AOBJS =  $(patsubst %.s, $(OBJSPATH)/%.o, $(SRCSASM))
COBJS =  $(patsubst %.c, $(OBJSPATH)/%.o, $(SRCS))

HFILES = libft.h

HEAD = $(patsubst %.h, $(INCPATH)/%.h, $(HFILES))

all: $(OBJSPATH) $(NAME)

$(NAME): casm $(AOBJS) ccf $(COBJS)
		@$(AR) -rc $@ $(AOBJS) $(COBJS)
		@$(RANLIB) $@
		@echo "\033[1;32;41m\nAll is done!\033[0m"

casm:
	@echo "\033[1;35;106mCompilation ASM\033[0m"

ccf:
	@echo "\033[1;33;105mCompilation libft\033[0m"

$(OBJSPATH)/%.o: $(SRCSASMPATH)/%.s
	@$(ASM) $(AFLAGS) -o $@ $<

$(OBJSPATH)/%.o: $(SRCSPATH)/%.c $(HEAD)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
		@/bin/rm -rf $(OBJSPATH)
		@echo "Delete objs file"

fclean: clean
		@/bin/rm -rf $(NAME)
		@echo "Delete objs file and executable"

re: fclean all

$(OBJSPATH) :
	@mkdir $@
