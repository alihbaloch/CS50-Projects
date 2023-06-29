# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 100000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO:

    # Read teams into memory from file

    # open csv file as a command line argument
    filename = sys.argv[1]
    with open(filename) as file:
        file_reader = csv.DictReader(file)
        # open each team's key and value in a dictionary
        for row in file_reader:
            # convert team ratings into integars
            row["rating"] = int(row["rating"])
            # append the dictionary into the list 'teams'
            teams.append(row)

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts

    # simulate N tournaments
    for i in range(N):
        # simulate the tournament with the given teams and store in winner
        winner = simulate_tournament(teams)
        # keep track of team wins
        if winner in counts:
            # increase number of wins by 1 if winner is already in the count
            counts[winner] += 1
        else:
            # add the first win for the team that just won for the first time
            counts[winner] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO

    # keep simulating rounds until only 1 team is left
    while len(teams) > 1:
        teams = simulate_round(teams)
    # return the winning team
    return teams[0]["team"]


if __name__ == "__main__":
    main()
