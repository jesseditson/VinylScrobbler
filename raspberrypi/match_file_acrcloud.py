from acrcloud.recognizer import ACRCloudRecognizer, ACRCloudRecognizeType
import sys

config = {
    'host': 'identify-us-west-2.acrcloud.com',
    'access_key': 'b7b74d5e2064676da61a8e563d5256c7',
    'access_secret': 'hhOxrt5HQS20JRmBA6DsbbKSdfkT2miDv1Zo8j3Z',
    'debug': True,
    'timeout': 10,
    'recognize_type': ACRCloudRecognizeType.ACR_OPT_REC_AUDIO
}

acrcloud = ACRCloudRecognizer(config)

def recognize(file):
    matches = acrcloud.recognize_by_file(file, 0)
    # matches = acrcloud.recognize(stream)

    print("matches: %s" % matches)

if __name__ == "__main__":
    # execute only if run as a script
    recognize(sys.argv[1])