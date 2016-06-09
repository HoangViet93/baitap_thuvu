/*
 *	hovaten: Vu Thi Le Thu
 *	lop: D12CN8
 *	ngay sinh: 8-5-1994
 * 	msv: xxxx7
 */

/* Library include */
#include <stdio.h>
#include <math.h>

/* funtion prototype */ 
void bai501_main(int is_write_to_text); /* Line 80 */
void bai502_main(void); /* Line 235 */
void bai503_main(void); /* Line 310 */
void bai504_main(void); /* Line 340 */
void bai505_main(void); /* Line 485 */ 
void bai506_main(void); /* Line 605 */
void bai507_main(void); /* Line 657 */
void bai509_main(void); /* Line 786 */
void bai510_main(void); /* Line 903 */
/*-----------------------------------------------------------------------------------------*/
/* MAIN PROGRAM */

int main (int argc, char **argv)
{	
	char baitap[50] = {0};

	printf("Ho va ten : Vu Thi Le Thu \n");
	printf("Lop : D12CN8\n");
	printf("Ma Sinh Vien xxxx7\n");
	printf("FPL-HW5\n");

	while(1) {
		printf("Moi nhap : tenbaitap<5.xx>: ");
		scanf("%s", baitap);

		if (strcmp(baitap, "5.01") == 0) {
			printf("Bai 5.01 - in ra man hinh ?\n");
			printf("Y/N : ");
			scanf("%s", baitap);
			if (strcmp(baitap, "y") == 0) {
				bai501_main(0);
			}
			else if (strcmp(baitap, "n") == 0) {
				bai501_main(1);
			}
			else {
				printf("error\n");
			}
		}
		else if (strcmp(baitap, "5.02") == 0) {
			bai502_main();
		}
		else if (strcmp(baitap, "5.03") == 0) {
			bai503_main();
		}
		else if (strcmp(baitap, "5.04") == 0) {
			bai504_main();
		}
		else if (strcmp(baitap, "5.05") == 0) {
			bai505_main();
		}
		else if (strcmp(baitap, "5.06") == 0) {
			bai506_main();
		}
		else if (strcmp(baitap, "5.07") == 0) {
			bai507_main();
		}
		else if (strcmp(baitap, "5.08") == 0) {
			printf("Giong bai 5.07\n");
		}
		else if (strcmp(baitap, "5.09") == 0) {
			bai509_main();
		}
		else if (strcmp(baitap, "5.10") == 0) {
			bai510_main();
		}
		else {
			printf("error\n");
		}
	}
} 
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* Global function */
void global_in_mang(int *xPtr, int N)
{
	int i = 0;

	printf("in_mang 1 chieu\n");
	for (i = 0; i < N; i++) {
		printf("gia tri phan tu %d la %d\n", i, *xPtr);
		xPtr++;
	}
	printf("\n");
}

void global_in_matrix(int **mxn_p, int m, int n)
{	
	int i, j = 0;

	printf("in ma tran \n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", mxn_p[i][j]);
		}
		printf("\n");
	}
}

/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 5.01 */

/* private variable */
char bai501_filename_read[3][20] = {"bai501_h", "bai501_l", "bai501_m"};
char bai501_filename_write[3][20] = {"bai501_h_ketqua", "bai501_l_ketqua", "bai501_m_ketqua"};

void (*bai501_draw_func_p[3])(int figure_row, char *file_write_path) = {NULL, NULL, NULL};

/* private function prototype */
int bai501_read_file(char *file_read_path);
void bai501_draw_figure_h(int figure_row, char *file_write_path);
void bai501_draw_figure_l(int figure_row, char *file_write_path);
void bai501_draw_figure_m(int figure_row, char *file_write_path);

/* Function Implement */
void bai501_main(int is_write_to_text)
{	
	int i = 0;
	int figure_row[3] = {0};

	printf("BAI501 : \n");

	bai501_draw_func_p[0] = &bai501_draw_figure_h;
	bai501_draw_func_p[1] = &bai501_draw_figure_l;
	bai501_draw_func_p[2] = &bai501_draw_figure_m;

	for (i = 0; i < 3; i++) {
		figure_row[i] = bai501_read_file(bai501_filename_read[i]);
		if (is_write_to_text == 1) {
			bai501_draw_func_p[i](figure_row[i], bai501_filename_write[i]);
		}
		else {
			bai501_draw_func_p[i](figure_row[i], NULL);
		}
	}
}

void bai501_draw_figure_h(int figure_row, char *file_write_path)
{	
	char tmp[] = {'A', 'B', 'C', 'D', 'E', 'D', 'C', 'B', 'A', '\n'};
	int i, j = 0;
	char figure_buff[100] = {0};

	for (i = 0; i < figure_row; i++) {
		memcpy(figure_buff + (i * sizeof(tmp)), tmp, sizeof(tmp));

		for (j = 0; j < sizeof(tmp); j++) {
			if (tmp[j] == ('E' - i)) {
				tmp[j] = ' ';
			}
		}
	}	
	if (file_write_path == NULL) {
		printf("figure H is \n");
		printf("%s\n", figure_buff);
	}
	else {
		FILE *file_p;
		file_p = fopen(file_write_path, "w+");
		fputs(figure_buff, file_p);
		fclose(file_p);
	}
}	

void bai501_draw_figure_l(int figure_row, char *file_write_path)
{
	char figure_buff[100] = {0};
	int i, j, k = 0;

	for (i = 0; i < figure_row; i++) {
		char tmp[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'};

		if (i < 4) {
			for (j = 3 - i; j < 5; j++) {
				tmp[j] = '1' + j - (3 - i);
			}
		}
		else {
			for (j = 1 + (i - 4); j < 5; j++) {
				tmp[j] = '1' + j - (1 + (i - 4));
			}
		}
		memcpy(figure_buff + i * sizeof(tmp), tmp, sizeof(tmp));
	}
	if (file_write_path == NULL) {
		printf("figure L is \n");
		printf("%s\n", figure_buff);
	}
	else {
		FILE *file_p;
		file_p = fopen(file_write_path, "w+");
		fputs(figure_buff, file_p);
		fclose(file_p);
	}
}

void bai501_draw_figure_m(int figure_row, char *file_write_path)
{
	int i, j, k = 0;
	char figure_buff[100] = {0};

	for (i = 0; i < 8; i++) {
		char tmp[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'};
		if (i < 4) {		
			for (j = i + 1; j < 9 - i - 1; j++) {
				tmp[j] = '*';	
			}
		}
		else {
			for (j = 3 - (i - 4); j < 9 - 3 + (i - 4); j++) {
				tmp[j] = '*';
			}
		}
		memcpy(figure_buff + i * sizeof(tmp), tmp, sizeof(tmp));
	}
	if (file_write_path == NULL) {
		printf("figure M is \n");
		printf("%s\n", figure_buff);
	}
	else {
		FILE *file_p;
		file_p = fopen(file_write_path, "w+");
		fputs(figure_buff, file_p);
		fclose(file_p);
	}
}

int bai501_read_file(char *file_read_path)
{
	char file_buff[10] = {0};
	FILE *file_p = NULL;
	int i = 0;

	file_p = fopen(file_read_path, "r");
	if (file_p == NULL) {
		printf("bai501_read_file: error openning %s text file\n", file_read_path);
		return -1;
	}

	for (i = 0; i < 10; i++) {
		int tmp;
		tmp = fgetc(file_p);
		/* doc va kiem tra ky tu EOF */
		if (tmp != 'E') {
			file_buff[i] = tmp;
		} 
		else {
			break;
		}
	}
	fclose(file_p);

	return atoi(file_buff);	
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 5.02 */

/* private function prototype */
static inline void bai502_hoandoi(int *so1, int *so2);
static inline int bai502_sosanhhon(int so1, int so2);
static inline int bai502_sosanhkem(int so1, int so2);
void bai502_sapxep(int (*sosanh)(int, int), int *array, int size);

/* private variables */
int (*bai502_sosanh_p)(int so1,int so2);

void bai502_main(void)
{	
	int i = 0;
	int array[5];

	printf("BAI502 : \n");
	printf("Day so test la : ");
	for (i = 0; i < 5; i++) {
		array[i] = rand() % 50;
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("Sap xep giam dan : ");
	bai502_sapxep(&bai502_sosanhhon, array, 5);
	for (i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	printf("Sap xep tang dan : ");
	bai502_sapxep(&bai502_sosanhkem, array, 5);
	for (i = 0; i < 5; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void bai502_sapxep(int (*sosanh)(int, int), int *array, int size)
{	
	int i, j, k = 0;

	for (i = 0; i < size - 1; i++) {
		for (j = size - 1; j > 0; j--) {
			if (sosanh(array[j], array[j - 1]) == 1) {
				bai502_hoandoi(&array[j], &array[j - 1]);
			}
		}
	}	
}

static inline void bai502_hoandoi(int *so1, int *so2)
{
	int tmp = 0;

	tmp = *so1;
	*so1 = *so2;
	*so2 = tmp;
}

static inline int bai502_sosanhhon(int so1, int so2)
{
	if (so1 > so2) {
		return 1;
	}
	else {
		return 0;
	}
}

static inline int bai502_sosanhkem(int so1, int so2)
{
	if (so1 <= so2) {
		return 1;
	}
	else {
		return 0;
	}	
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 5.03 */
void bai503_main(void)
{	
	int *xPtr = NULL;

	printf("BAI503 : \n");

	xPtr = (int*)malloc(sizeof(int));
	printf("Moi nhap vao so nguyen : ");
	scanf("%d", xPtr);
	printf("Gia tri nhap vao la %d\n", *xPtr);

	free(xPtr);
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 5.04 */

/* private function prototype */
int bai504_cap_phat(int **xPtr);
void bai504_nhap_gia_tri(int *xPtr, int N);
void global_in_mang(int *xPtr, int N);
void bai504_random_array(int *xPtr, int N);
int bai504_read_array_from_file(char *file_name, int **xPtr);
int bai504_timsolonnhat(int *xPtr, int N);
int bai504_timsonhonhat(int *xPtr, int N);
int bai504_demsochan(int *xPtr, int N);

void bai504_main(void)
{
	int *xPtr = NULL;
	int N = 0;

	printf("BAI504 : \n");

	N = bai504_cap_phat(&xPtr);
	bai504_nhap_gia_tri(xPtr, N);
	global_in_mang(xPtr, N);

	bai504_random_array(xPtr, N);
	global_in_mang(xPtr, N);
	free(xPtr);
	xPtr = NULL;

	N = bai504_read_array_from_file("bai504_array_info", &xPtr);
	global_in_mang(xPtr, N);
	printf("max = %d\n", bai504_timsolonnhat(xPtr, N));
	printf("min = %d\n", bai504_timsonhonhat(xPtr, N));
	printf("so chan = %d\n", bai504_demsochan(xPtr, N));

	free(xPtr);
}

int bai504_cap_phat(int **xPtr) 
{
	int N = 0;

	printf("bai504_cap_phat\n");
	printf("Moi nhap kich thuoc mang yeu cau : ");
	scanf("%d", &N);
	printf("\n");

	*xPtr = (int*)malloc(sizeof(int) * N);

	return N;	
}

void bai504_nhap_gia_tri(int *xPtr, int N)
{	
	int i = 0;

	printf("bai504_nhap_gia_tri\n");
	for (i = 0; i < N; i++) {
		printf("Moi nhap gia tri phan tu %d = ", i);
		scanf("%d", xPtr);
		xPtr++;
	}	
	printf("\n");
}

void bai504_random_array(int *xPtr, int N)
{	
	int i = 0;

	printf("bai504_random_array\n");

	for (i = 0; i < N; i++) {
		*xPtr = rand() % 50;
		xPtr++;
	}	
}

int bai504_read_array_from_file(char *file_name, int **xPtr)
{	
	int N = 0;
	char tmp = 0;
	int i = 0;
	int *tmp_p;
	FILE *file_p;

	printf("bai504_read_array_from_file\n");

	file_p = fopen(file_name, "r");
	tmp = fgetc(file_p);
	N = atoi(&tmp);

	*xPtr = (int*)malloc(sizeof(int) * N);
	tmp_p = *xPtr;
	for (i = 0; i < N; i++) {
		tmp = fgetc(file_p);
		tmp_p[i] = atoi(&tmp);
	}
	fclose(file_p);

	return N;
}

int bai504_timsolonnhat(int *xPtr, int N)
{	
	int i = 0;
	int max = 0;

	max = xPtr[0];
	for (i = 0; i < N - 1; i++) {
		if (max < xPtr[i + 1]) {
			max = xPtr[i + 1];
		}
	}
	return max;	
}

int bai504_timsonhonhat(int *xPtr, int N)
{
	int i = 0;
	int min = 0;

	min = xPtr[0];
	for (i = 0; i < N - 1; i++) {
		if (min > xPtr[i + 1]) {
			min = xPtr[i + 1];
		}
	}
	return min;		
}

int bai504_demsochan(int *xPtr, int N)
{
	int i = 0;
	int tmp = 0;

	for (i = 0; i < N; i++) {
		if (xPtr[i] % 2 != 0) {
			tmp++;
		}
	}
	return tmp;	
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 5.05 */

/* private variables */
const int default_k = 5;

/* private function prototype */
int bai505_cap_phat(int **xPtr);
void bai505_random_array(int *xPtr, int N);
int bai505_morong_mang(int **xPtr, int N, int k);
void bai505_in_mang_rafile(char *file_name, int *xPtr, int N);

void bai505_main(void)
{
	int *xPtr = NULL;
	int N = 0;

	printf("BAI505 : \n");

	N = bai505_cap_phat(&xPtr);
	bai505_random_array(xPtr, N);
	global_in_mang(xPtr, N);
	bai505_in_mang_rafile("bai505_mang", xPtr, N);

	N = bai505_morong_mang(&xPtr, N, default_k);
	global_in_mang(xPtr, N);
	bai505_in_mang_rafile("bai505_mangmorong", xPtr, N);

	free(xPtr);
}

int bai505_cap_phat(int **xPtr) 
{
	int N = 0;

	printf("bai505_cap_phat\n");
	printf("Moi nhap kich thuoc mang yeu cau : ");
	scanf("%d", &N);
	printf("\n");

	*xPtr = (int*)malloc(sizeof(int) * N);

	return N;	
}

void bai505_in_mang_rafile(char *file_name, int *xPtr, int N)
{
	FILE *file_p;
	int i = 0;

	printf("bai505_in_mang_ra file\n");
	file_p = fopen(file_name, "w");
	fprintf(file_p, "kich thuoc mang %d\n", N);
	fprintf(file_p, "gia tri mang : ");
	for (i = 0; i < N; i++)
	{
		fprintf(file_p, "%d ", xPtr[i]);
	}
	fprintf(file_p, "\n");

	fclose(file_p);
}

void bai505_random_array(int *xPtr, int N)
{	
	int i = 0;

	printf("bai505_random_array\n");

	for (i = 0; i < N; i++) {
		*xPtr = rand() % 50;
		xPtr++;
	}	
}

int bai505_timsonhonhat(int *xPtr, int N)
{
	int i = 0;
	int min = 0;

	for (i = 0; i < N - 1; i++) {
		if (xPtr[i] >= 0) {
			min = xPtr[i];
		}
	}

	for (i = 0; i < N - 1; i++) {
		if (min > xPtr[i] && xPtr[i] >= 0) {
			min = xPtr[i];
		}
	}	

	return min;		
}

int bai505_morong_mang(int **xPtr, int N, int k)
{	
	int i = 0;
	int *diff_p = NULL;
	int extend_N;

	printf("bai505_morong_mang\n");

	if (N >= (int)pow(2, k)) {
		return -1;
	}

	diff_p = malloc(sizeof(int) * k);
	for (i = 1; i <= k; i++) {
		diff_p[i - 1] = (int)pow(2, i) - N;
	}
	extend_N = bai505_timsonhonhat(diff_p, k);
	extend_N += N;
	printf("k gan nhat la %d\n", extend_N);
	free(diff_p);
	diff_p = NULL;

	*xPtr = (int *)realloc(*xPtr, (sizeof(int)) * extend_N);
	diff_p = *xPtr;
	for (i = N; i < extend_N; i++)
	{
		diff_p[i] = 0;
	}
	return extend_N;
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 5.06 */

void bai506_main(void)
{
	int i = 5, j = 6, k = 7;
	int *ptr1, *ptr2;
	int **ptr2ptr;

	printf("BAI506 : \n");

	/* tang len 1 don vi */
	ptr1 = &i;
	ptr2 = &j;
	ptr2ptr = &ptr1;
	**ptr2ptr = **ptr2ptr + 1;  
	ptr2ptr = &ptr2;
	**ptr2ptr = **ptr2ptr + 1;
	*ptr2ptr = &k;
	**ptr2ptr = **ptr2ptr + 1;
	printf("tang len 1 : i = %d, j = %d, k = %d\n", i, j, k);

	/* giam di 1 don vi */
	ptr1 = &i;
	ptr2 = &j;
	ptr2ptr = &ptr1;
	**ptr2ptr = **ptr2ptr - 1;  
	ptr2ptr = &ptr2;
	**ptr2ptr = **ptr2ptr - 1;
	*ptr2ptr = &k;
	**ptr2ptr = **ptr2ptr - 1;
	printf("giam di 1 : i = %d, j = %d, k = %d\n", i, j, k);

	/* tang kich thuong gap doi */
	ptr1 = &i;
	ptr2 = &j;
	ptr2ptr = &ptr1;
	**ptr2ptr = **ptr2ptr * 2;  
	ptr2ptr = &ptr2;
	**ptr2ptr = **ptr2ptr * 2;
	*ptr2ptr = &k;
	**ptr2ptr = **ptr2ptr * 2;
	printf("nhan doi : i = %d, j = %d, k = %d\n", i, j, k);
}
/*-----------------------------------------------------------------------------------------*/


/*-----------------------------------------------------------------------------------------*/
/* BAI 5.07 */

/* private function prototype */
int bai507_timsolonnhat(int **mxn_p, int m, int n);
int bai507_timsonhonhat(int **mxn_p, int m, int n);
void bai507_random_array(int **mxn_p, int m, int n);

void bai507_main(void)
{
	int m, n = 0;
	int i,j = 0;
	int **mxn_p;

	printf("BAI507 : \n");

	/* nhap vao kich thuoc mang */
	printf("Moi nhap vao so hang : ");
	scanf("%d", &m);
	printf("Moi nhap vao so cot : ");
	scanf("%d", &n);

	/* cap phat mang */
	mxn_p = (int**)malloc(sizeof(int*) * m);
	for (i = 0; i < m; i++) {
		mxn_p[i] = (int*)malloc(sizeof(int) * n);
	}

	/* nhap vao phan tu */
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("Moi nhap vao phan tu [%d][%d] : ", i, j);
			scanf("%d", &mxn_p[i][j]);
		}
	}
	global_in_matrix(mxn_p, m, n);
	printf("so lon nhat cua mang vua nhap : ");
	printf("%d\n", bai507_timsolonnhat(mxn_p, m, n));
	for (i = 0; i < m; i++) {
		printf("so lon nhat tai hang %d la %d\n", i, bai504_timsolonnhat(mxn_p[i], n));
	}

	printf("so nho nhat cua mang vua nhap : ");
	printf("%d\n", bai507_timsonhonhat(mxn_p, m, n));
	for (i = 0; i < m; i++) {
		printf("so nho nhat tai hang %d la %d\n", i, bai504_timsonhonhat(mxn_p[i], n));
	}

	/* mang random */
	bai507_random_array(mxn_p, m, n);
	global_in_matrix(mxn_p, m, n);
	printf("so lon nhat cua mang vua nhap : ");
	printf("%d\n", bai507_timsolonnhat(mxn_p, m, n));
	for (i = 0; i < m; i++) {
		printf("so lon nhat tai hang %d la %d\n", i, bai504_timsolonnhat(mxn_p[i], n));
	}

	printf("so nho nhat cua mang vua nhap : ");
	printf("%d\n", bai507_timsonhonhat(mxn_p, m, n));
	for (i = 0; i < m; i++) {
		printf("so nho nhat tai hang %d la %d\n", i, bai504_timsonhonhat(mxn_p[i], n));
	}

	for (i = 0; i < m; i++) {
		free(mxn_p[i]);
	}
	free(mxn_p);
}

void bai507_random_array(int **mxn_p, int m, int n)
{	
	int i, j = 0;

	printf("bai507_random_array\n");

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			mxn_p[i][j] = rand() % 50;
		}
	}
}

int bai507_timsolonnhat(int **mxn_p, int m, int n)
{	
	int i, j = 0;
	int max = 0;

	max = mxn_p[0][0];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n-1; j++) {
			if (max < mxn_p[i][j+1]) {
				max = mxn_p[i][j+1]; 
			}
		}
	}
	return max;	
}

int bai507_timsonhonhat(int **mxn_p, int m, int n)
{	
	int i, j = 0;
	int min = 0;

	min = mxn_p[0][0];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n-1; j++) {
			if (min > mxn_p[i][j+1]) {
				min = mxn_p[i][j+1]; 
			}
		}
	}
	return min;	
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 5.08 */
/* bai nay em da lam tuong tu bai 5.07, chia lam cac ham con tuong ung */
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 5.09 */

/* private function */
void bai509_a(int **ptr, int *array, int N, int L, int *newsize);
void bai509_b(int **ptr, int *array, int N, int *newsize);
int bai509_c(int ***ptr2ptr, int *array, int N, int m, int n);

/* private variables */
const int m = 2;
const int n = 4;
const int L = 1;

void bai509_main(void)
{	
	int i = 0;
	int newsize = 0;
	int array[6] = {-1, 1, 2, 3, 4, 5};
	int **ptr2ptr;
	int *ptr;

	printf("BAI509 : \n");

	/* cau a */
	bai509_a(&ptr, array, 6, L, &newsize);
	global_in_mang(ptr, newsize);
	free(ptr);
	ptr = NULL;

	/* cau b */
	bai509_b(&ptr, array, 6, &newsize);
	global_in_mang(ptr, newsize);
	free(ptr);
	ptr = NULL;

	/* cau c */
	bai509_c(&ptr2ptr, array, 6, m, n);
	global_in_matrix(ptr2ptr, m, n);
	for (i = 0; i < m; i++) {
		free(ptr2ptr[i]);
	}
	free(ptr2ptr);
}

void bai509_a(int **ptr, int *array, int N, int L, int *newsize)
{	
	int i, j, k = 0;
	int *tmp_p;

	printf("bai509_a\n");

	if (L > N) {
		return NULL;
	}

	j = 0;
	for (i = 0; i < N; i += L + 1) {
		j++;
	}
	*newsize = j;

	*ptr = (int *)malloc(sizeof(int) * j);
	for (k = 0; k < j; k++) {
		(*ptr)[k] = array[k*(L+1)];
	}
}

void bai509_b(int **ptr, int *array, int N, int *newsize)
{
	int i, j, k = 0;
	*newsize = N + (N - 1);

	*ptr = (int*)malloc(sizeof(int) * (*newsize));

	for (i = 0; i < (*newsize); i++) {
		if (i % 2 != 0) {
			(*ptr)[i] = 0;
		}
		else {
			(*ptr)[i] = array[i / 2]; 
		}
	}
}

int bai509_c(int ***ptr2ptr, int *array, int N, int m, int n)
{	
	int i, j, k = 0;

	*ptr2ptr = (int**)malloc(sizeof(int*) * m);
	for (i = 0; i < m; i++) {
		(*ptr2ptr)[i] = (int*)malloc(sizeof(int) * n);
	}

	if (m * n < N) {
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				(*ptr2ptr)[i][j] = array[k + j];
			}
			k += i + j;
		}
		return -1;
	}
	else if (m * n == N) {
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				(*ptr2ptr)[i][j] = array[k + j];
			}
			k += i + j;
		}
		return 0;		
	}
	else {
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (k + j > N - 1) {
					(*ptr2ptr)[i][j] = 0;
				} else {
					(*ptr2ptr)[i][j] = array[k + j];
				}
			}
			k += i + j;
		}
		return 0;				
	}
}
/*-----------------------------------------------------------------------------------------*/



/*-----------------------------------------------------------------------------------------*/
/* BAI 5.10 */

/* private function */
int bai510_cap_phat(int **ptr, int nStart, int nStop, int nStep);

/* private variable */
const int g_nStart = 0;
const int g_nStop = 5;
const int g_nStep = 1;

void bai510_main(void) 
{
	int *ptr;
	int N = 0;

	printf("BAI510 : \n");
	N = bai510_cap_phat(&ptr, g_nStart, g_nStop, g_nStep);
	global_in_mang(ptr, N);
}

int bai510_cap_phat(int **ptr, int nStart, int nStop, int nStep)
{	
	int i = 0;
	*ptr = (int)malloc(sizeof(int) *(nStop - nStart));

	for (i = 0; i < (nStop - nStart); i++) {
		(*ptr)[i] = i + nStep;
	}

	return nStop - nStart;
}
/*-----------------------------------------------------------------------------------------*/
/* END */
