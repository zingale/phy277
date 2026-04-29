titles = ["a new hope",
          "the empire strikes back",
          "return of the jedi",
          "the phantom menace",
          "attack of the clones",
          "revenge of the sith",
          "the force awakens",
          "the last jedi",
          "the rise of skywalker"]

# sort by string length
titles.sort(key=lambda s: len(s))

for s in titles:
    print(s)

