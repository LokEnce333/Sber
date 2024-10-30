from flask import Flask, request, jsonify, render_template
from openpyxl import Workbook, load_workbook
import os

app = Flask(__name__)

# Имя файла Excel, куда будут сохраняться ответы
EXCEL_FILE = 'C:\Codes\IMBA_DP.xlsx'

# Если файл Excel не существует, создаём его и добавляем заголовок
if not os.path.exists(EXCEL_FILE):
    workbook = Workbook()
    sheet = workbook.active
    sheet.append(['Answer'])  # Заголовок для столбца
    workbook.save(EXCEL_FILE)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/survey')
def survey():
    return render_template('survey.html')

@app.route('/submit', methods=['POST'])
def submit():
    data = request.get_json()
    answer = data.get('answer')

    if answer:
        # Открываем Excel и добавляем ответ в новую строку
        workbook = load_workbook(EXCEL_FILE)
        sheet = workbook.active
        sheet.append([answer])
        workbook.save(EXCEL_FILE)
        return jsonify({'status': 'success'}), 200
    else:
        return jsonify({'status': 'error', 'message': 'No answer provided'}), 400

if __name__ == '__main__':
    app.run(debug=True)