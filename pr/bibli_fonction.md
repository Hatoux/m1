# Lien entre bibliotheques et fonctions #

- \<unistd.h\>
	+ pid_t fork(void)
	+ pid_t getpid(void)
	+ pid_t getppid(void)
	+ uid_t getuid(void) : retourne l'uid reel
	+ uid_t geteuid(void) : retourne l'uid effectif du processus appelant
- \<errno.h\>
	+ errno : variable globale qui contient le code d'erreur produit lors de l'execution du programme
- \<sys/types.h\>
	+ uid_t : correspond a un unsigned int => %u pour affichage


