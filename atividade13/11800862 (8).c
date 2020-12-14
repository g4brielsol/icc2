#include <stdio.h>
#include <math.h>



typedef struct Point {
	float x, y;
} Point;

// cabeçalho das funcoes utilizadas
float min(float x, float y);
float dist(Point p1, Point p2);
void sort(Point p[], int c, int f);
float closest(Point p[], int c, int f);

int main() 
{
	int n;
	scanf("%d", &n);
	Point points[n];

	for(int i=0; i<n; i++) {
		scanf("%f %f", &points[i].x, &points[i].y);
	}

	int v = n-1;
	sort(points, 0, v);

	printf("%.6f", closest(points, 0, v));

	return 0;
}

//funcoes utilizadas 

float min(float x, float y) 
{
	if(x<y)
		return x;
	else
		return y;
}

float dist(Point p1, Point p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)); 
}

void sort(Point p[], int c, int f) 
{
	if(c==f)
		return;

	int f1 = (c+f)/2;
	int c2 = f1 + 1;

	sort(p, c, f1);
	sort(p, c2, f);

	Point prov[(f-c) + 1];

	int s = f-c+1;

	int p1 = c, p2 = c2, t=0;

	do {
		if(p[p1].x <= p[p2].x) {
			prov[t] = p[p1];
			p1++, t++;
		}
		else {
			prov[t] = p[p2];
			p2++, t++;
		}
	} while(p2 <= f && p1 <= f1);

	for(; p1<=f1; p1++, t++) {
		prov[t] = p[p1];
	}

	for(; p2<=f; p2++, t++) {
		prov[t] = p[p2];
	}

	for(int i=c, t=0; t<s; i++, t++) {
		p[i] = prov[t];
	} 


}

float closest(Point p[], int c, int f) 
{
	if(c==f) 
		return 1000;

	int f1 = (c+f)/2;
	int c2 = f1+1;

	float dir = closest(p, c2, f);
	float esq = closest(p, c, f1);
	float less = min(esq, dir);

	int p1 = f1;
	int p2 = c2;

	while(p[p2].x - p[p1].x < less && p1 >= 0) {
		while(p[p2].x - p[p2].x < less && p2 <= f) {
			less = min(dist(p[p1], p[p2]), less);
			p2 += 1;
		}

		p1 -= 1;
		p2 = c2;
	}

	return less;
}

