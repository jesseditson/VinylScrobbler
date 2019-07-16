from dejavu import Dejavu
from dejavu_config import CONFIG
import sys

djv = Dejavu(CONFIG)
djv.fingerprint_directory(sys.argv[1], [".mp3", ".mp4", ".wav"], 4)
