
// Take a set of student answers and an answer key, and return a vector
// of scores, one per student.
vector<int> studentScores(const ResponseSet& studentAnswers, const Answers& key) {
    // the list of scores to return
    vector<int> scores;

    size_t numStudents = studentAnswers.size();
    size_t numQuestions = key.size();
    for (size_t studentNumber = 0; studentNumber < numStudents; ++studentNumber) {
        // compute this student's score
        int score = 0;
        for (size_t questionNumber = 0; questionNumber < numQuestions; ++questionNumber) {
            if (studentAnswers.at(???).at(???) == key.at(???)) {
                ++score;
            }
        }
        // add to the list of scores we will return
        scores.push_back(score);
    }
    return scores;
}