
vector<int> studentScores(const ResponseSet& studentAnswers, const Answers& key) {
    size_t numStudents = studentAnswers.size();
    size_t numQuestions = key.size();

    vector<int> scores;
    for (size_t studentNumber = 0; studentNumber < numStudents; ++studentNumber) {
        int score = 0;
        for (size_t questionNumber = 0; questionNumber < numQuestions; ++questionNumber) {
            if (studentAnswers.at(???).at(???) == key.at(???)) {
                ++score;
            }
        }
        scores.push_back(score);
    }
    return scores;
}