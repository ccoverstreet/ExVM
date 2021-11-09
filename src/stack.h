// Fixed Stack Implementation
// Cale Overstreet
// Nov. 8, 2021

#pragma once

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct {
	uint32_t *stack;
	uint32_t size;
	int sp; // Stack Pointer
} FixedStack;

FixedStack *FixedStack_create(uint32_t stack_size);
void FixedStack_destroy(FixedStack *stack);

void FixedStack_print(FixedStack *stack);

int FixedStack_push(FixedStack *stack, uint32_t val);
int FixedStack_pop(FixedStack *stack, uint32_t *dest);
