CHECKER = checker.out

PUSH_SWAP = push_swap.out

LIBFT = ./libft/libft.a

CHECKER_SRC = \
	$(addprefix ./src/, \
		add_arguments.c \
		checker.c \
		verbose.c \
		execute_instructions.c \
		get_instructions.c \
		solve_check.c \
		free.c \
		$(addprefix instructions/, \
			instr_sa_sb_ss.c \
			instr_pa_pb.c \
			instr_ra_rb_rr.c \
			instr_rra_rrb_rrr.c \
		) \
	) \


CHECKER_OBJ = $(CHECKER_SRC:.c=.o)

HEADERS = -I ./src -I ./libft

CFLAGS = -Wall -Wextra -Werror

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(LIBFT) $(CHECKER_OBJ)
	gcc $(CFLAGS) -o $@ $^

$(PUSH_SWAP): $(LIBFT)
	@echo "no push_swap yet :("

%.o: %.c
	gcc $(CFLAGS) $(HEADERS) -c -o $@ $<

$(LIBFT):
	@echo building libft
	cd ./libft && $(MAKE)

clean:
	rm -f $(CHECKER_OBJ)
	cd ./libft && $(MAKE) fclean
fclean: clean
	rm -f $(CHECKER) $(PUSH_SWAP)
re: fclean all

.PHONY: all clean fclean $(LIBFT)