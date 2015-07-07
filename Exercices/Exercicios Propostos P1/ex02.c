int CaixaPreta(int A[], int n) {
    int k=0, i=1, j=0;
    int h;
    while (i<n && k+j+1<n ) {   /* pior caso: i ou k e j aumentam devagar */
        if (A[k+j] == A[(i+j)%n]) { /* sozinha essa condição pode levar a O(n) */
            j = j+1;    /* j aumenta 1 */
        }
        else if (A[k+j] < A[(i+j)%n]) { /* sozinha essa condição pode levar a O(n) */
            i = i+j+1;  /* i aumenta bastante */
            j = 0;      /* porém j zera */
        }
        else if (A[k+j] > A[(i+j)%n]) { /* sozinha essa condição pode levar a O(n) */
            h = max(i, k+j+1);
            k = h;      /* k aumenta bastante */
            i = h+1;    /* i aumenta bastante */
            j = 0;      /* porém j zera */
        }
    }
    return k;
}

/*!
  * Conjungando a primeira e a segunda condição o pior que se consegue é algo
  * em torno de T(n) = 2n -> O(n).
  * ....
  * .... complicado....
  */
