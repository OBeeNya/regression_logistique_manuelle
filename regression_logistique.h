#ifndef REGRESSION_LOGISTIQUE_H
# define REGRESSION_LOGISTIQUE_H

# define TRAIN_LEN 3785
# define TEST_LEN 1865
# define NB_OF_VARS 45

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

typedef struct s_obs
{
	int	intercept;
	int	x0_Baccalauréat;
	int	x0_Diplôme_de_l_enseignement_supérieur;
	int	x0_Niveau_Bac_2;
	int	x0_Sans_diplôme_certificat_d_études;
	int	x1_Artisan_commerçant_chef_d_entreprise;
	int	x1_Employé;
	int	x1_Enseignant;
	int	x1_Etudiant_élève;
	int	x1_N_a_jamais_travaillé;
	int	x1_Ouvrier;
	int	x1_Profession_intermédiaire;
	int	x1_Profession_libérale_cadre_supérieur;
	int	x2_N_a_pas_d_ascendance_étrangère;
	int	x2_N_a_qu_un_grand_parent;
	int	x2_Nsp;
	int	x3_25_34_ans;
	int	x3_35_49_ans;
	int	x3_50_64_ans;
	int	x3_65_ans_et_plus;
	int	x4_HOMME;
	int	x5_GRAND_EST;
	int	x5_GRAND_NORD;
	int	x5_GRAND_OUEST;
	int	x5_GRAND_SUD_EST;
	int	x5_GRAND_SUD_OUEST;
	int	x5_ILE_DE_FRANCE;
	int	x6_Autre;
	int	x6_Chômage;
	int	x6_Elève_étudiant;
	int	x6_Nsp;
	int	x6_Retraité;
	int	x6_Travaille;
	int	x7_Divorcé_ne_vivant_pas_en_couple;
	int	x7_Divorcé_vivant_en_couple;
	int	x7_Marié;
	int	x7_Nsp;
	int	x7_Pacsé;
	int	x7_Veuf_ou_veuve_ne_vivant_pas_en_couple;
	int	x7_Veuf_ou_veuve_vivant_en_couple;
	int	x7_Vivant_en_couple_sans_être_marié;
	int	x8_Catholique_non_pratiquant;
	int	x8_Catholique_pratiquant;
	int	x8_Nsp;
	int	x8_Sans_religion;
	int	Y;
}	t_obs;

#endif
