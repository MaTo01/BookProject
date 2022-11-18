# Progetto Book

Progettare e implementare la classe Book che rappresenta un libro in una biblioteca. Tale classe ha membri per contenere:

		• ISBN
		• Titolo
		• Nome e cognome autore (due membri diversi)
		• Data di copyright – la data è rappresentata usando una apposita classe Date 
		  simile a quella sviluppata a lezione
		• Stato in prestito / disponibile

Il codice ISBN può essere rappresentata mediante una std::string oppure una classe dedicata. In ogni caso, l’ISBN deve avere il formato 
n-n-n-x, con n intero e x una singola cifra o una lettera (i quattro campi sono separati da un carattere ‘-’).

La classe Book deve essere dotata di:

  		• Funzioni membro che ritornano i vari campi
  		• Costruttori
  		• Funzioni per registrare il prestito e la restituzione
  		• Appositi strumenti (eventualmente implementati nella classe dedicata) per la 
		  validazione del formato ISBN e della data
  		• Operator== e operator!= che confrontano due libri basandosi sul codice ISBN
  		• Operator<< che stampa titolo, autore, ISBN e la data di copyright su righe separate in output

La classe Book (e le altre eventuali classi) devono essere correttamente separate nei file .h e .cpp e deve essere prevista la creazione di librerie dedicate.
Un ulteriore file .cpp deve contenere il main, usato per i test. È apprezzato l’utilizzo di Cmake.

Oltre ai test necessari per lo sviluppo, devono essere compilabili le seguenti istruzioni:

  		• std::vector<Book> shelf(10);
  		• Book my_favourite_book(“David”, “Foster Wallace”, “Una cosa divertente 
		  che non farò mai più”, “887-521-837-4”);

