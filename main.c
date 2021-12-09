#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ctype.h>

void test();

int next(char *book, int current, int max_len);

bool check_char(char c);

const int max_value = 256;
const int resolution = 500;
/**
 * prob[a][b][c]
 */
float prob[256][256][256];
int value_len = 0;
char values[256];
int buffer[256];

int gen_len;
/**
 * len of book
 */
int len;

bool isBigChar(char c) {
    if (c >= 65 && c <= 90) {
        // BIG CHARACTER
        return true;
    }
    return false;
}
/**
 * checks if char is to be accounted for
 * @param c
 * @return
 */
bool check_char(char c) {
    if (c >= 65 && c <= 90) {
        // BIG CHARACTER
        return true;
    }
    if (c >= 97 && c <= 122) {
        // SMALL CHARACTER
        return true;
    }
    if (c == 32 || c == 44 || c == 46) {
        //printf("Returning true\n");
        return true;
    }
    //printf("Returning false for:%c\n", c);
    return false;
}

/**
 * should only be executed after check_char
 * @param c
 * @return
 */
char convert_char(char c) {
    if (c >= 65 && c <= 90) {
        c = c + 32;
    }
    return c;
}


int next(char *book, int current, int _len) {
    //printf("Starting with %d ->", current);
    for (int i = current + 1; i < _len; i++) {
        if (check_char(book[i])) {
            //printf("found char %c at %d\n", book[i], i);
            return i;
        }
    }
    return -1;
}

/**
 * A03_4.1 Bauen sie ein dreidimensionales Feld auf...
 * notes occurrences of c existing after a and b.
 * @param book
 */
void read(char *book) {
    int c = 0;
    for (int i = 32; i <= 122; i++) {
        //printf("Checking %c|%d\n", intToChar(i), i);
        if (check_char((char) i)) {
            if (isBigChar(i))
                continue;
            //printf("valid\n");

            values[c++] = (char) i;

            value_len += 1;
        }
    }
    printf("[INFO]Checking values array ... \n");
    for (int i = 0; i < value_len; i++) {
        printf("[INFO]value[%d]= %c;%d\n", i, values[i], (values[i]));
    }
    int i = 0;
    char c0 = book[next(book, 0, len)];
    char c1 = book[next(book, next(book, 0, len), len)];
    char c2 = book[next(book, next(book, next(book, 0, len), len), len)];
    int current = 0;
    long l = 0;
    while (true) {
        l += 1;
        if ((l % 45000) == 0) {
            printf("[INFO]Progress :%2lf\n", (float) current / (float) len);
            printf("[INFO]Current: %d; current lenth: %d; total length: %d\n", current, l, len);
            printf("[INFO]Selected %c,%c,%c\n", c0, c1, c2);
        }
        // check chars afterwards too
        while (!check_char(c0)) {
            current = next(book, current, len);
            if (current == -1) {
                break;
            }
            c0 = book[current];
        }
        if (current == -1) {
            break;
        }
        while (!check_char(c1)) {
            current = next(book, current, len);
            if (current == -1) {
                break;
            }
            c1 = book[current];
        }
        if (current == -1) {
            break;
        }
        while (!check_char(c2)) {
            current = next(book, current, len);
            if (current == -1) {
                break;
            }
            c2 = book[current];
        }
        if (current == -1) {
            break;
        }
        c0 = convert_char(c0);
        c1 = convert_char(c1);
        c2 = convert_char(c2);

        //printf("inserting %d,%d,%d", c0, c1, c2);
        //printf("||| %d,%d,%d\n", charToInt(c0), charToInt(c1), charToInt(c2));
        double d = prob[c0][c1][c2];
        prob[c0][c1][c2] = d + 1.0;
        //if (c0 == 'a' && c1 == 'b') {
        //printf("Added %f for %c\n", d + 1.0, c2);
        //}
        c0 = c1;
        c1 = '~';
        c2 = '~';
    }
    printf("[INFO]Done!\n");
}


/**
 * A03_4.1 Bauen sie ein dreidimensionales Feld auf...
 *
 */
void eval() {
    printf("[INFO]Evaluating data!\n");
    for (int i0 = 0; i0 < value_len; i0++) {
        for (int i1 = 0; i1 < value_len; i1++) {
            double n = 0;
            for (int i2 = 0; i2 < value_len; i2++) {
                n += prob[values[i0]][values[i1]][values[i2]];
            }
            if (n == 0) continue;
            for (int i2 = 0; i2 < value_len; i2++) {
                //printf("calculated %d->%c->%c = %f\n", intToChar(values[i0]), intToChar(values[i1]),
                //       intToChar(values[i2]),
                //       (prob[values[i0]][values[i1]][values[i2]] / (double) n));
                prob[values[i0]][values[i1]][values[i2]] =
                        prob[values[i0]][values[i1]][values[i2]] / (double) n;
            }
        }
    }
    printf("[INFO]Done!\n");
}

char vector_array[500];
long deb = 0;

/**
 * A03_4.2 Erzeugen eines Vektors...
 * @param i0 Erster Index für das Feld prob[][][], also prob[i0][][]
 * @param i1 Zweiter Index für das Feld prob[][][], also prob[i0][i1][]
 * @return
 */
void vector(int i0, int i1) {
    if (deb % 30 == 0)printf("[INFO]Generating vector!\n");
    float offset = 0;
    int c = 0;
    for (int i = 0; i < value_len; i++) {
        //printf("|l...| char = <%c><%d>\n", values[i], (int) values[i]);
        int index = (int) values[i];
        float p = (prob[i0][i1][index]) + offset;
        float d = 0;
        //printf("Iterating... c = %d, prob = %lf, d = %lf\n", c, p, d);
        while (d < p) {
            //printf("char = %c ", values[i]);
            //printf("Iterating... c = %d, prob = %lf, d = %lf\n", c, p, d);

            if (c == 500) {
                if (deb % 30 == 0)printf("[WARNING]Exiting vector generation early...\n");
                return;
            }
            vector_array[c] = values[i];
            d += (1.0f / (float) resolution);
            c += 1;
        }
        //printf("Remaining offset:%lf\n", offset);
        offset = p - d;
        //printf("Remaining offset:%lf\n", offset);
    }
    if (deb % 30 == 0)printf("[INFO]Vector generated!\n");
    deb += 1;
}

int random(int bound) {
    return rand() % bound;
}

/**
 * A03_4.3 Erzeugen eines zufälliges Textes...
 * @param text_len Länge des Texts.
 */
void generate(int text_len) {
    printf("[INFO]Generating random text...\n");
    char *array = malloc(text_len + 1);
    char c0 = '.';
    char c1 = ' ';
    printf("Small text for <.>< >...\n");
    for (int i = 0; i < value_len; i++) {
        printf("[INFO]value: %lf\n", prob[c0][c1][values[i]]);
    }
    for (int i = 0; i < 10000; i++) {
        if (random(500) >= 500) {
            printf("[ERROR]Random is > 500. \n");
        }
    }
    array[0] = c0;
    array[1] = c1;
    for (int i = 2; i < text_len; i++) {
        vector((int) c0, (int) c1);
        array[i] = vector_array[random(500)];
        //for (int i = 0; i < 500; i++) {
        //    printf("%c", vector_array[i]);
        //}
        c0 = c1;
        c1 = array[i];
    }
    printf("[INFO]Done!\n");
    printf("[INFO]Output text:\n\n");

    FILE *fPtr;
    fPtr = fopen("output.txt", "w");

    if (fPtr == NULL) {
        printf("[ERROR]Unable to create file. Output text that was supposed to be stored:\n\n");
        for (int i = 0; i < text_len; i++) {
            printf("%c", array[i]);
        }
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < text_len; i++) {
        printf("%c", array[i]);
        fputc(array[i], fPtr);
    }
    printf("\n\n");
    fclose(fPtr);

    printf("[INFO]File <output.txt> created and saved successfully. \n");
}

void simulate() {
    printf("Starting calculations...");
    FILE *fp;
    long lSize;
    char *buffer;
    fp = fopen("moby-dick.txt", "rb");
    if (!fp) perror("moby-dick.txt"), exit(1);

    fseek(fp, 0L, SEEK_END);
    lSize = ftell(fp);
    rewind(fp);
    buffer = calloc(1, lSize + 1);
    if (!buffer) fclose(fp), fputs("memory alloc fails", stderr), exit(1);

    if (1 != fread(buffer, lSize, 1, fp))
        fclose(fp), free(buffer), fputs("entire read fails", stderr), exit(1);
    char *buffer2 = malloc(lSize + 1);
    int size = 0;
    for (int i = 0; i < lSize; i++) {
        buffer2[i] = buffer[i];
        size++;
    }

/* do your work here, buffer is a string contains the whole text */
    printf("Executing!");
    len = size;
    read(buffer2);
    eval();
    test();
    generate(gen_len);
}

void test() {
    double d = 0;
    for (int i = 0; i < value_len; i++) {
        //printf("Value for %c:%f\n", values[i], prob['.'][' '][values[i]]);
        d += prob['.'][' '][values[i]];
    }
    printf("[INFO]TEST RESULT:%lf \n", d);
}

int main(int argc, char **argv) {
    if (argc > 2) {
        printf("Too many arguments!<%d>", argc);
        return 0;
    } else if (argc <= 1) {
        printf("No arguments!\n");
        printf("Enter the length for the generated text:");
        scanf("%d", &gen_len);
    } else {
        gen_len = atoi(argv[1]);
    }
    printf("---!\n");
    for (int i = 0; i < 256; i++) {
        buffer[i] = -1;
    }
    printf("---!\n");
    for (int i0 = 0; i0 < 256; i0++)
        for (int i1 = 0; i1 < 256; i1++)
            for (int i2 = 0; i2 < 256; i2++)
                prob[i0][i1][i2] = 0;
    printf("---!\n");
    srand(time(NULL));
    printf("---!\n");
    simulate();
    return 0;
}

