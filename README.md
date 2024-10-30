
---

# Minishell

Repositorio raíz: [Minishell en GitHub](https://github.com/Leined18/Minishell)

Este proyecto implementa una versión básica de un shell en C. La organización del proyecto sigue la siguiente estructura, con enlaces directos a cada archivo.

## Estructura del Proyecto

### `inc/`
- [`config.h`](https://github.com/Leined18/Minishell/blob/main/inc/config.h)
- [`minishell.h`](https://github.com/Leined18/Minishell/blob/main/inc/minishell.h)

### `libft/`
- [`main.c`](https://github.com/Leined18/Minishell/blob/main/libft/main.c)
- [`Makefile`](https://github.com/Leined18/Minishell/blob/main/libft/Makefile)
- [`README.md`](https://github.com/Leined18/Minishell/blob/main/libft/README.md)

#### `libft/inc/`
- [`ft_printf.h`](https://github.com/Leined18/Minishell/blob/main/libft/inc/ft_printf.h)
- [`get_next_line.h`](https://github.com/Leined18/Minishell/blob/main/libft/inc/get_next_line.h)
- [`libft.h`](https://github.com/Leined18/Minishell/blob/main/libft/inc/libft.h)
- [`shared.h`](https://github.com/Leined18/Minishell/blob/main/libft/inc/shared.h)
- [`structs.h`](https://github.com/Leined18/Minishell/blob/main/libft/inc/structs.h)

#### `libft/srcs/cmd/`
- [`ft_create_child.c`](https://github.com/Leined18/Minishell/blob/main/libft/srcs/cmd/ft_create_child.c)
- [`ft_create_cmd.c`](https://github.com/Leined18/Minishell/blob/main/libft/srcs/cmd/ft_create_cmd.c)
- [`ft_execmd.c`](https://github.com/Leined18/Minishell/blob/main/libft/srcs/cmd/ft_execmd.c)
- [`ft_get_cmd_path.c`](https://github.com/Leined18/Minishell/blob/main/libft/srcs/cmd/ft_get_cmd_path.c)
- [`ft_handle_parent.c`](https://github.com/Leined18/Minishell/blob/main/libft/srcs/cmd/ft_handle_parent.c)
- [`ft_parse_cmd.c`](https://github.com/Leined18/Minishell/blob/main/libft/srcs/cmd/ft_parse_cmd.c)
- [`ft_pipe_cmd.c`](https://github.com/Leined18/Minishell/blob/main/libft/srcs/cmd/ft_pipe_cmd.c)
- [`ft_redirect_input.c`](https://github.com/Leined18/Minishell/blob/main/libft/srcs/cmd/ft_redirect_input.c)
- [`ft_redirect_output.c`](https://github.com/Leined18/Minishell/blob/main/libft/srcs/cmd/ft_redirect_output.c)

### `src/`

#### `src/builtins/`
- [`builtins.h`](https://github.com/Leined18/Minishell/blob/main/src/builtins/builtins.h)
- [`cd.c`](https://github.com/Leined18/Minishell/blob/main/src/builtins/cd.c)
- [`echo.c`](https://github.com/Leined18/Minishell/blob/main/src/builtins/echo.c)
- [`env.c`](https://github.com/Leined18/Minishell/blob/main/src/builtins/env.c)

#### `src/commands/`
- [`commands.c`](https://github.com/Leined18/Minishell/blob/main/src/commands/commands.c)
- [`commands.h`](https://github.com/Leined18/Minishell/blob/main/src/commands/commands.h)
- [`execute_command.c`](https://github.com/Leined18/Minishell/blob/main/src/commands/execute_command.c)
- [`find_command_path.c`](https://github.com/Leined18/Minishell/blob/main/src/commands/find_command_path.c)

#### `src/env/`
- [`env_get.c`](https://github.com/Leined18/Minishell/blob/main/src/env/env_get.c)
- [`env.h`](https://github.com/Leined18/Minishell/blob/main/src/env/env.h)
- [`env_init.c`](https://github.com/Leined18/Minishell/blob/main/src/env/env_init.c)
- [`env_set.c`](https://github.com/Leined18/Minishell/blob/main/src/env/env_set.c)

### `src/errors/`
- [`error_handling.c`](https://github.com/Leined18/Minishell/blob/main/src/errors/error_handling.c)
- [`error_messages.c`](https://github.com/Leined18/Minishell/blob/main/src/errors/error_messages.c)
- [`errors.h`](https://github.com/Leined18/Minishell/blob/main/src/errors/errors.h)

### `src/input/`
- [`input.h`](https://github.com/Leined18/Minishell/blob/main/src/input/input.h)
- [`lexer.c`](https://github.com/Leined18/Minishell/blob/main/src/input/lexer.c)
- [`parser.c`](https://github.com/Leined18/Minishell/blob/main/src/input/parser.c)
- [`tokenizer.c`](https://github.com/Leined18/Minishell/blob/main/src/input/tokenizer.c)

### `src/interpreter/`
- [`command_executor.c`](https://github.com/Leined18/Minishell/blob/main/src/interpreter/command_executor.c)
- [`command_handler.c`](https://github.com/Leined18/Minishell/blob/main/src/interpreter/command_handler.c)
- [`command_router.c`](https://github.com/Leined18/Minishell/blob/main/src/interpreter/command_router.c)
- [`interpreter.h`](https://github.com/Leined18/Minishell/blob/main/src/interpreter/interpreter.h)

### `src/memory/`
- [`garbage_collector.c`](https://github.com/Leined18/Minishell/blob/main/src/memory/garbage_collector.c)
- [`memory.h`](https://github.com/Leined18/Minishell/blob/main/src/memory/memory.h)
- [`memory_utils.c`](https://github.com/Leined18/Minishell/blob/main/src/memory/memory_utils.c)

### `src/shell/`
- [`cleanup.c`](https://github.com/Leined18/Minishell/blob/main/src/shell/cleanup.c)
- [`init.c`](https://github.com/Leined18/Minishell/blob/main/src/shell/init.c)
- [`loop.c`](https://github.com/Leined18/Minishell/blob/main/src/shell/loop.c)
- [`main.c`](https://github.com/Leined18/Minishell/blob/main/src/shell/main.c)
- [`shell.c`](https://github.com/Leined18/Minishell/blob/main/src/shell/shell.c)
- [`shell.h`](https://github.com/Leined18/Minishell/blob/main/src/shell/shell.h)
- [`utils.c`](https://github.com/Leined18/Minishell/blob/main/src/shell/utils.c)

### `src/signals/`
- [`signal_handler.c`](https://github.com/Leined18/Minishell/blob/main/src/signals/signal_handler.c)
- [`signals.h`](https://github.com/Leined18/Minishell/blob/main/src/signals/signals.h)
- [`signal_utils.c`](https://github.com/Leined18/Minishell/blob/main/src/signals/signal_utils.c)

---

Con estos enlaces, el README cubre todos los archivos del proyecto `src/` y sus subcarpetas.

*(Continúa con el resto de los archivos en `src/` y sus subcarpetas como `errors`, `input`, `interpreter`, `memory`, `shell`, y `signals`, manteniendo el mismo estilo de formato para cada archivo.)*

---
