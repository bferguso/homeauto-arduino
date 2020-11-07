from flask import request
from flask import Flask, render_template
from flask import Response
from homeServer.HomeServerDao import HomeServerDao
import simplejson as json
import datetime
import decimal
app = Flask(__name__)
app.debug = True
app.filename = "/var/www/html/log/environment.log"

#app.run(debug=True,host="0.0.0.0")
def verify_token(password):
    passw = 'thisisourtoken'
    if password == passw:
        return True

    return False

@app.route('/')
def showHomePage():
    return render_template("home.html", ip="192.168.102.124")

@app.route('/inventory')
def getinventory():
    if not verify_token(request.args.get('token')):
        return ('token did not matched')
    data = {"message":"Have a great day"}
    data = json.dumps(data)
    resp = Response(response=data,
                    status=200,
                    mimetype="application/json")
    return resp

@app.route('/logEnv')
def logEnv():
    obj = json.loads(request.args.get('envJson'))
    obj['date'] = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
#    file1 = open(app.filename, "a")
#    file1.write(json.dumps(obj))
#    file1.write("\n")
#    file1.close();
    obj['status']="success"
    resp = Response(response=json.dumps(obj),
                    status=200,
                    mimetype="application/json")
    dao = HomeServerDao()
    dao.saveEnvironmentLog(obj)

    return resp

@app.route('/readEnv')
def readEnv():
    dao = HomeServerDao()
    last_log = dao.getLastEnvironmentLog()
    #response_body = dict(map(lambda x: (x[0], convert_value(x[1])), last_log.items() ))
    return render_template("menu.html", latest_env=last_log, env_summary=dao.getEnvironmentLogSummary())


def convert_value(value):
    if isinstance(value, (datetime.datetime, datetime.date, datetime.time)):
        return value.isoformat()
    if isinstance(value, (decimal.Decimal)):
        return float(value)
    return value

if __name__ == "__main__":
    app.run(host='0.0.0.0',port=5000)
