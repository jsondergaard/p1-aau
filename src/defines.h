#define DBFILE "../database.db"

#define YELLOW "\x1b[33m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

#define ERRCHECK                                                                   \
	{                                                                              \
		if (rc != SQLITE_OK)                                                       \
		{                                                                          \
			fprintf(stderr, RED "Database error: %s\n" RESET, sqlite3_errmsg(db)); \
			sqlite3_close(db);                                                     \
		}                                                                          \
	}