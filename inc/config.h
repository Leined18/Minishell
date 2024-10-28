#ifndef CONFIG_H
# define CONFIG_H

// Macros para funciones y operaciones
# define _(...) (__VA_ARGS__)  // Ejecuta las acciones pasadas como argumentos
# define SQUARE(x) ((x) * (x)) // Devuelve el cuadrado de x
// Macro para imprimir mensajes de debug
# define DEBUG(msg) \
ft_printf("DEBUG: %s (in %s at line %d)\n", msg, __func__,__LINE__)
	// Definiciones de mensajes
# define SUCCESS "\033[1;32m✅ Success: Function finished well!\n\033[0m"
	// Verde
# define ERROR "\033[1;31m❌ Error: Error in function!\n\033[0m"
	// Rojo
# define WARNING "\033[1;33m⚠️ Warning: Warning in function!\n\033[0m"
	// Amarillo

# define HANDLE_ERROR(msg) \
	do                    \
	{                     \
		ft_error(msg, 1); \
	} while (0)

	// Macro para concatenar nombres
# define CONCAT(x, y) x##y
# define NAME(x) CONCAT(my_var_, x)

	// Macro para setear campos en estructuras
# define SET_FIELD(obj, field, value) (obj.field = value)
# define GET_FIELD(obj, field) (obj.field)

	// Macro para setear punteros en estructuras
# define SET_FIELD_PTR(obj, field, value) (obj->field = value)
# define GET_FIELD_PTR(obj, field) (obj->field)

	// Macro para liberar memoria
# define FREE(ptr)   \
	do              \
	{               \
		free(ptr);  \
		ptr = NULL; \
	} while (0)

#endif // CONFIG_H