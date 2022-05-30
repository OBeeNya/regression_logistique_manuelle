#include "regression_logistique.h"

long double	ft_sigmoid(long double x)
{
	return (1 / (1 + exp(-x)));
}

void	ft_gradient_descent(int train[TRAIN_LEN][NB_OF_VARS], long double *theta, long double alpha, int iterations)
{
	long double	H[TRAIN_LEN];
	long double	Z[NB_OF_VARS];
	int			i;
	int			j;

	while(iterations--)
	{
		i = 0;
		while (i < TRAIN_LEN)
		{
			H[i] = 0.0;
			j = 0;
			while (j < NB_OF_VARS)
				H[i] += (long double)train[i][j] * theta[j++];
			H[i] = ft_sigmoid(H[i]);
			H[i] -= (long double)train[i][NB_OF_VARS];
			i++;
		}
		j = 0;
		while (j < NB_OF_VARS)
		{
			Z[j] = 0.0;
			i = 0;
			while (i < TRAIN_LEN)
				Z[j] += (long double)train[i][j] * H[i++];
			Z[j] *= (long double)alpha / (long double)TRAIN_LEN;
			theta[j] -= Z[j];
			j++;
		}
	}
}

void	ft_predict(int test[TEST_LEN][NB_OF_VARS], long double *theta, long double *pred)
{
	int	i;
	int	j;

	i = 0;
	while (i < TEST_LEN)
	{
		j = 0;
		while (j < NB_OF_VARS)
			pred[i] += test[i][j] * theta[j++];
		pred[i] = round(ft_sigmoid(pred[i]));
		i++;
	}
}

int	main(void)
{
	FILE 		*ftx;
	FILE 		*fty;
	int			train[TRAIN_LEN][NB_OF_VARS];
	int			test[TEST_LEN][NB_OF_VARS];
	int			i;
	long double	theta[45] = {0.0};
	long double pred[TEST_LEN] = {0.0};

	ftx = fopen("df_SA_co_train_X.csv", "r");
	if (!ftx)
		return (1);
	fty = fopen("df_SA_co_train_Y.csv", "r");
	if (!fty)
		return (1);
	i = 0;
	while (i < TRAIN_LEN)
	{
		train[i][0] = 1;
		fscanf(ftx, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", \
		&train[i][1],
		&train[i][2],
		&train[i][3],
		&train[i][4],
		&train[i][5],
		&train[i][6],
		&train[i][7],
		&train[i][8],
		&train[i][9],
		&train[i][10],
		&train[i][11],
		&train[i][12],
		&train[i][13],
		&train[i][14],
		&train[i][15],
		&train[i][16],
		&train[i][17],
		&train[i][18],
		&train[i][19],
		&train[i][20],
		&train[i][21],
		&train[i][22],
		&train[i][23],
		&train[i][24],
		&train[i][25],
		&train[i][26],
		&train[i][27],
		&train[i][28],
		&train[i][29],
		&train[i][30],
		&train[i][31],
		&train[i][32],
		&train[i][33],
		&train[i][34],
		&train[i][35],
		&train[i][36],
		&train[i][37],
		&train[i][38],
		&train[i][39],
		&train[i][40],
		&train[i][41],
		&train[i][42],
		&train[i][43],
		&train[i][44]);
		i++;
	}
	i = 0;
	while (i < TRAIN_LEN)
	{
		fscanf(fty, "%d", &train[i][45]);
		i++;
	}
	fclose(ftx);
	fclose(fty);
	ft_gradient_descent(train, theta, 0.3, 10000);
	ftx = fopen("df_SA_co_test_X.csv", "r");
	if (!ftx)
		return (1);
	fty = fopen("df_SA_co_test_Y.csv", "r");
	if (!fty)
		return (1);
	i = 0;
	while (i < TEST_LEN)
	{
		test[i][0] = 1;
		fscanf(ftx, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", \
		&test[i][1],
		&test[i][2],
		&test[i][3],
		&test[i][4],
		&test[i][5],
		&test[i][6],
		&test[i][7],
		&test[i][8],
		&test[i][9],
		&test[i][10],
		&test[i][11],
		&test[i][12],
		&test[i][13],
		&test[i][14],
		&test[i][15],
		&test[i][16],
		&test[i][17],
		&test[i][18],
		&test[i][19],
		&test[i][20],
		&test[i][21],
		&test[i][22],
		&test[i][23],
		&test[i][24],
		&test[i][25],
		&test[i][26],
		&test[i][27],
		&test[i][28],
		&test[i][29],
		&test[i][30],
		&test[i][31],
		&test[i][32],
		&test[i][33],
		&test[i][34],
		&test[i][35],
		&test[i][36],
		&test[i][37],
		&test[i][38],
		&test[i][39],
		&test[i][40],
		&test[i][41],
		&test[i][42],
		&test[i][43],
		&test[i][44]);
		i++;
	}
	i = 0;
	while (i < TEST_LEN)
	{
		fscanf(fty, "%d", &test[i][45]);
		i++;
	}
	fclose(ftx);
	fclose(fty);
	ft_predict(test, theta, pred);
	i = 0;
	int	j = 0;
	while (i < TEST_LEN)
	{
		if (pred[i] == test[i][45])
			j++;
		i++;
	}
	printf("precision: %.2f%% \n", (float)j * 100 / TEST_LEN);
	return (0);
}






	// 	train[i].intercept = 1;
	// 	fscanf(ftx, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", \
	// 	&train[i].x0_Baccalauréat,
	// 	&train[i].x0_Diplôme_de_l_enseignement_supérieur,
	// 	&train[i].x0_Niveau_Bac_2,
	// 	&train[i].x0_Sans_diplôme_certificat_d_études,
	// 	&train[i].x1_Artisan_commerçant_chef_d_entreprise,
	// 	&train[i].x1_Employé,
	// 	&train[i].x1_Enseignant,
	// 	&train[i].x1_Etudiant_élève,
	// 	&train[i].x1_N_a_jamais_travaillé,
	// 	&train[i].x1_Ouvrier,
	// 	&train[i].x1_Profession_intermédiaire,
	// 	&train[i].x1_Profession_libérale_cadre_supérieur,
	// 	&train[i].x2_N_a_pas_d_ascendance_étrangère,
	// 	&train[i].x2_N_a_qu_un_grand_parent,
	// 	&train[i].x2_Nsp,
	// 	&train[i].x3_25_34_ans,
	// 	&train[i].x3_35_49_ans,
	// 	&train[i].x3_50_64_ans,
	// 	&train[i].x3_65_ans_et_plus,
	// 	&train[i].x4_HOMME,
	// 	&train[i].x5_GRAND_EST,
	// 	&train[i].x5_GRAND_NORD,
	// 	&train[i].x5_GRAND_OUEST,
	// 	&train[i].x5_GRAND_SUD_EST,
	// 	&train[i].x5_GRAND_SUD_OUEST,
	// 	&train[i].x5_ILE_DE_FRANCE,
	// 	&train[i].x6_Autre,
	// 	&train[i].x6_Chômage,
	// 	&train[i].x6_Elève_étudiant,
	// 	&train[i].x6_Nsp,
	// 	&train[i].x6_Retraité,
	// 	&train[i].x6_Travaille,
	// 	&train[i].x7_Divorcé_ne_vivant_pas_en_couple,
	// 	&train[i].x7_Divorcé_vivant_en_couple,
	// 	&train[i].x7_Marié,
	// 	&train[i].x7_Nsp,
	// 	&train[i].x7_Pacsé,
	// 	&train[i].x7_Veuf_ou_veuve_ne_vivant_pas_en_couple,
	// 	&train[i].x7_Veuf_ou_veuve_vivant_en_couple,
	// 	&train[i].x7_Vivant_en_couple_sans_être_marié,
	// 	&train[i].x8_Catholique_non_pratiquant,
	// 	&train[i].x8_Catholique_pratiquant,
	// 	&train[i].x8_Nsp,
	// 	&train[i].x8_Sans_religion);
	// 	fscanf(fty, "%d", &train[i].Y);
	