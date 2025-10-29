def n_grams(text: str, n: int) -> list[tuple]:

    words = text.split(" ")
    # Handle edge case
    if n > len(words):
        return []
    
    # Generate n slices, each shifted by 1
    slices = [words[i:] for i in range(n)]
    return list(zip(*slices))

# Test with different n values
result2 = n_grams("what is this works", 2)
result3 = n_grams("what is this works", 3)
result4 = n_grams("what is this works", 4)

print("2-grams:", result2)
print("3-grams:", result3)
print("4-grams:", result4)

