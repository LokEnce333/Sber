from fastapi import FastAPI, Request, HTTPException
import pandas as pd
from datetime import datetime

app = FastAPI()
DATABASE_PATH = "IMBA_DP.xlsx"

# Чтение данных из Excel
def load_data():
    return pd.read_excel(DATABASE_PATH)

# Сохранение данных в Excel
def save_data(df):
    df.to_excel(DATABASE_PATH, index=False)

# API: Получить доступные опросы
@app.get("/surveys")
def get_surveys():
    data = load_data()
    available_surveys = data[['SurveyID', 'SubSurvey']].drop_duplicates()
    return available_surveys.to_dict(orient="records")

# API: Записать результаты опроса
@app.post("/submit")
async def submit_survey(request: Request):
    data = await request.json()
    user_id = data["user_id"]
    survey_id = data["survey_id"]
    subsurvey = data["subsurvey"]
    answer = data["answer"]
    dp = data["dp"]

    df = load_data()
    new_entry = {
        "UserID": user_id,
        "SurveyID": survey_id,
        "SubSurvey": subsurvey,
        "Answer": answer,
        "DP": dp,
        "DateCompleted": datetime.now().strftime("%Y-%m-%d")
    }
    df = df.append(new_entry, ignore_index=True)
    save_data(df)
    return {"message": "Survey submitted successfully!"}