from telegram import Update, InlineKeyboardButton, InlineKeyboardMarkup, WebAppInfo
from telegram.ext import Application, CommandHandler, ContextTypes
import logging

TOKEN = '7356286056:AAFAD2LgFe7SY26gxKW45BiMcXIEAf-L7PM'
VIDEO_PATH = 'aaa.mp4'

logging.basicConfig(level=logging.INFO)


async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):
    # Открываем и отправляем видео
    with open(VIDEO_PATH, 'rb') as video:
        await update.message.reply_video(video)

    # Создаем WebApp кнопку
    web_app = WebAppInfo(url="https://ecd28bf4b956ba.lhr.life")  # Укажите ссылку на своё веб-приложение
    button = InlineKeyboardButton("Open Mini App", web_app=web_app)
    keyboard = InlineKeyboardMarkup([[button]])

    # Отправляем сообщение с кнопкой
    await update.message.reply_text("Click the button to open the Mini App:", reply_markup=keyboard)


def main():
    # Создаем объект Application
    app = Application.builder().token(TOKEN).build()

    # Регистрируем обработчик команды /start
    app.add_handler(CommandHandler("start", start))

    # Запускаем бота
    app.run_polling()


if __name__ == "__main__":
    main()
