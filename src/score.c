// src/score.c（プレーンテキスト, UTF-8, 改行はLF推奨）
#include "score.h"

int calc_average_score(int size, const int scores[]) {
    if (size <= 0 || scores == 0) return 0;
    long sum = 0;
    for (int i = 0; i < size; ++i) sum += scores[i];
    return (int)(sum / size);
}
