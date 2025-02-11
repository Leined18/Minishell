#ifndef CONFIG_H
# define CONFIG_H

// Include any necessary headers here
# include <asm-generic/ioctls.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

// Macros para funciones y operaciones
# define SQUARE(x) ((x) * (x))     // Devuelve el cuadrado de x
# define CUBE(x) ((x) * (x) * (x)) // Devuelve el cubo de x

# define SUCCESS "\033[1;32m✅ Success: Function finished well!\n\033[0m"
// Verde
# define ERROR "\033[1;31m❌ Error: Error in function!\n\033[0m"
// Rojo
# define WARNING "\033[1;33m⚠️ Warning: Warning in function!\n\033[0m"

# define USAGE "Usage: %s <string>\n"
// Amarillo
// Macro para concatenar nombres
# define CONCAT(x, y) x##y
# define NAME(x) CONCAT(my_var_, x)

#endif // CONFIG_H
