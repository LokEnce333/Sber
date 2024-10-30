from telegram import Bot, Update, WebAppInfo, InlineKeyboardButton, InlineKeyboardMarkup
from telegram.ext import CommandHandler, CallbackContext, Updater

TOKEN = '7356286056:AAFAD2LgFe7SY26gxKW45BiMcXIEAf-L7PM'

def start(update: Update, context: CallbackContext):
    web_app = WebAppInfo(url="https://lokence333.github.io/Sber/")  # Укажи ссылку на своё веб-приложение
    button = InlineKeyboardButton("Open Mini App", web_app=web_app)
    keyboard = InlineKeyboardMarkup([[button]])
    update.message.reply_text("Click the button to open the Mini App:", reply_markup=keyboard)

def main():
    updater = Updater(TOKEN)
    dp = updater.dispatcher

    dp.add_handler(CommandHandler("start", start))

    updater.start_polling()
    updater.idle()

if __name__ == "__main__":
    main()