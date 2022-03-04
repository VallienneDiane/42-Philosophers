# PHILOSOPHERS

Nouvelles notions : threads, mutex, data race, sémaphore (bonus)

## Lancer le programme :

``` ./philo nb_philo time_to_die time_to_eat time_to_sleep nb_time_each_philo_must_eat(option)```

``` ./philo 4 410 200 200 7```

## Partie Obligatoire

### Philosophers avec des threads et des mutex 

Des philosophes sont assis autour d’une table ronde au centre de laquelle se trouve un grand plat de spaghetti. Les philosophes sont soit en train de manger, de penser ou de dormir.

Il y a également des fourchettes sur la table. Il y a autant de fourchettes que de philosophes. Puisque servir et manger des spaghetti à l’aide d’une seule fourchette n’est pas chose facile, un philosophe prend la fourchette sur sa gauche et celle sur sa droite, soit une fourchette dans chaque main, afin de manger.

Quand un philosophe a fini de manger, il repose les fourchettes sur la table et se met à dormir. Une fois réveillé, il se remet à penser. La simulation prend fin si un philosophe meurt de faim.


Fonctions externes autorisées :

memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock


## Partie Bonus

### Philosophers avec des processus et des sémaphores

Les règles spécifiques à la partie bonus sont :
• Toutes les fourchettes sont au centre de la table.
• Elles n’ont pas d’état spécifique en mémoire, mais le nombre de fourchettes disponibles est représenté par un sémaphore.
• Chaque philosophe est représenté par un processus différent. Cependant, le processus principal ne doit pas être un philosophe.

Fonctions externes autorisées :

memset, printf, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink