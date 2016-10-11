#TD3 (suite)#

| bob: Biliothequaire | sigb: SIGB |
|---------------------|------------|
| selectionEnregistrerEmprunt() ---> | |
|| <---- afficheFormulaire() |
|| rechercheAbo("u007") |
|| <---- verifierDroitEmprunt("u007") |
| emprunter("20kex1")----> ||
|| rechercheExemplaire("20kex1") |
|| verifierStatus("20kex1") |
|| enregistrerEmprunt("u007", "20kex1", 10/10/2016, 10/11/2016) |
| finirEmprunt() ||

si on decide de remprunter un bouquin on fait: 

| bob: Biliothequaire | sigb: SIGB |
|---------------------|------------|
| selectionEnregistrerEmprunt() ---> | |
|| <---- afficheFormulaire() |
|| rechercheAbo("u007") |
|| <---- verifierDroitEmprunt("u007") |
| emprunter("20kex1")----> ||
|| rechercheExemplaire("20kex1") |
|| verifierStatus("20kex1") |
|| enregistrerEmprunt("u007", "20kex1", 10/10/2016, 10/11/2016) |
| finirEmprunt() ||
|| verifierDroitEmprunt("u007") |
|| <---- verifierDroitEmprunt("u007") |
| emprunter("20kex1")----> ||
|| rechercheExemplaire("21kex1") |
|| verifierStatus("21kex1") |
|| enregistrerEmprunt("u007", "21kex1", 10/10/2016, 10/11/2016) |
| finirEmprunt() ||


"20kex1" et "u007 sont des informations que l'acteur doit fournir.

| SIGB||
|----||
| selectionEnregistrerEmprunt() ||
| demarrerEmprunt(idAbo:String) ||
| recherherAbo(idAbo:String)||
| verifierDroitEmprunt(idAbo:String)||
| enregistrerEmprunt(idAbo:String, idEx:String, dateDebut:Date, dateFin:Date)||
|||
|||


Titre: Enregistrement retour
Desc: un bib enregistre le retour d'un ex
Acteur:bib (principale ou stagiaire)
Pré: rien
SN:

1. le bib choisit "enregistrer retour"
2. le systeme affiche un formulaire de saisie
	id exemplaire + selecteur d'etat (Neuf .....)
3. le bib saisit l'id de l'exemplaire et son etat percu et valide
4. le systeme recherche l'emprunt lié à l'exemplaire et nettoie
5. le systeme met à jour le status exemplaire "en rayon", son etat libere la capacité d'emprunt aboné
6. le systeme affiche la liste des emprunts restant de l'abonné

post: le statut et l'etat exemplaire maj / l emprunt est detruit


A1: probleme saisie
    En SN4, si l'exemplaire n'est pas trouvé ou que son statut n'est pas "En pret"
    retour en SN2

A2: Degradation
    En SN5, si l'etat de l'exemplaire a baissé de pus de 3niveaux:
    A2.1: le systeme calcule le motant amande et l'affiche
    A2.2 le bib valide
    A2.3 retourn en SN5

A3: Travau
    En SN5, si etat = endommagé
    A3.1: le systeme affiche "Envoyer en traveaux"
    A3.2: le bib valide
    retour en SN6
