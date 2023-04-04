/**
 * \file merge_sort.c
 * \brief Merge sort.
 * \date 2017
 * \author YOU
 * \copyright WTFPLv2
 */

/* Copyright © 2017 YOU <you@etu.unistra.fr>
 *
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar.
 *
 * See http://www.wtfpl.net/ or read below for more details.
 */
/* DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *                    Version 2, December 2004
 *
 * Copyright (C) 2004 Sam Hocevar <sam@hocevar.net>
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *            DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE FUCK YOU WANT TO.
 */
#include "custom_sort.h"

#include "array.h"

////////////////////////////////////////////////////////////////////////////////
// Your implementation.
////////////////////////////////////////////////////////////////////////////////
void tri_fusion(long int* const array, int a, int b){
    if(a >= b) return;
    int m = (a+b)/2;
    tri_fusion(array, a, m);
    tri_fusion(array, m+1,b);
    long int* tab = (long int*)malloc(sizeof(long int)*(b-a+1));
    int i = a;
    int j = m+1;
    int k = 0;
    while(i <= m && j <= b) {
        if(array[i] < array[j]) {
            tab[k] = array[i]; i++; k++;
        } else {
            tab[k] = array[j]; j++; k++;
        }
    }
    while(i <= m){
        tab[k] = array[i]; i++; k++;
    }
    while(j <= b) {
        tab[k] = array[j]; j++; k++;
    }
    for(i = 0; i < b-a+1; i++){
        array[a+i] = tab[i];
    }
    free(tab);
}

long int* custom_sort(size_t size, long int* const array)
{
    tri_fusion(array, 0, size-1);
    return array;
}

////////////////////////////////////////////////////////////////////////////////
// Other required functions.
////////////////////////////////////////////////////////////////////////////////

const char* custom_sort_name(void)
{
  return "merge_sort()";
}
